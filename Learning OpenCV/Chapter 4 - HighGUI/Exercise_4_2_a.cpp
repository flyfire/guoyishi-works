////////////////////////////////////////
// Page: 107
// Exercises: Chapter 4 - 2.a
// Creator: Yishi Guo
// Data: 20090916
////////////////////////////////////////
#include <cv.h>
#include <highgui.h>
#include <iostream>
#include <sstream>
#include <stdio.h>
using namespace std;

bool is_display = false;
CvPoint point = cvPoint( 0, 0 );
CvPoint down_point = cvPoint( 0, 0 );
CvSize frame_size = cvSize( 0, 0 );

IplImage* doPyrDown( IplImage* in, int filter = IPL_GAUSSIAN_5x5 ) {
	// Best to make sure input image is divisible by two.
	//
	assert( in->width%2 == 0 && in->height%2 == 0 );

	IplImage* out = cvCreateImage(
		cvSize( in->width/2, in->height/2 ),
		in->depth,
		in->nChannels
	);
	cvPyrDown( in, out, filter );
	return ( out );
}

IplImage* doGray ( IplImage* in ) {
	IplImage* out = cvCreateImage(
		cvSize( in->width, in->height ),
		in->depth,
		1
	);

	cvCvtColor ( in, out, CV_RGB2GRAY );

	return out;
}

IplImage* doNotGray ( IplImage* in, int nChannels = 3 ) {
	IplImage* out = cvCreateImage(
		cvSize( in->width, in->height ),
		in->depth,
		nChannels
	);

	cvCvtColor ( in, out, CV_GRAY2RGB );

	return out;
}

IplImage* doCanny (
	IplImage* in,
	double lowThresh = 10,
	double highThresh = 100,
	double aperture = 3
	) {
	if ( in->nChannels != 1 ) return 0;

	IplImage* out = cvCreateImage(
		cvGetSize( in ),
		in->depth,
		1
	);

	cvCanny( in, out, lowThresh, highThresh, aperture );
	return ( out );
}

IplImage* three_in_one( IplImage* frame_half, IplImage* frame_half_gray, IplImage* frame_half_canny ) {
	IplImage* frame_half_gray_3_Channel = NULL;
	IplImage* frame_half_canny_3_Channel = NULL;

	IplImage* frame_three_in_one = cvCreateImage(
		cvSize(frame_half->width * 3, frame_half->height),
		frame_half->depth,
		frame_half->nChannels
	);

	cvSetImageROI( frame_three_in_one, cvRect(0, 0, frame_half->width, frame_half->height));
	cvSetImageROI( frame_half, cvRect(0, 0, frame_half->width, frame_half->height ));
	cvCopy( frame_half, frame_three_in_one );
	cvResetImageROI( frame_three_in_one );
	cvResetImageROI( frame_half );

	cvSetImageROI( frame_three_in_one, cvRect(frame_half->width, 0, frame_half->width, frame_half->height ));
	frame_half_gray_3_Channel = doNotGray( frame_half_gray, frame_half->nChannels );
	cvSetImageROI( frame_half_gray_3_Channel, cvRect( 0, 0, frame_half->width, frame_half->height ) );
	cvCopy( frame_half_gray_3_Channel, frame_three_in_one );
	cvResetImageROI( frame_three_in_one );
	cvResetImageROI( frame_half_gray_3_Channel);

	cvSetImageROI( frame_three_in_one, cvRect(frame_half->width * 2, 0, frame_half->width, frame_half->height ));
	frame_half_canny_3_Channel = doNotGray( frame_half_canny, frame_half->nChannels );
	cvSetImageROI( frame_half_canny_3_Channel, cvRect(0, 0, frame_half->width, frame_half->height) );
	cvCopy( frame_half_canny_3_Channel, frame_three_in_one );
	cvResetImageROI( frame_three_in_one );
	cvResetImageROI( frame_half_canny_3_Channel );

	cvReleaseImage( &frame_half_gray_3_Channel );
	cvReleaseImage( &frame_half_canny_3_Channel );

	return ( frame_three_in_one );
}

void my_mouse_callback(
	int event, int x, int y, int flags, void* param
	){
	IplImage* image = (IplImage*) param;
	
	switch ( event ) {
		case CV_EVENT_LBUTTONDOWN: {
			is_display = true;

			if ( x < 0 ) x = 0;
			if ( y < 0 ) y = 0;
			if ( x > frame_size.width*3 ) x = frame_size.width*3;
			if ( y > frame_size.height ) y = frame_size.height;

			down_point.x = x;
			down_point.y = y;
			
			// Put the x value to individual
			if ( frame_size.width <= x && x < frame_size.width*2 ) x -= frame_size.width;
			else if (frame_size.width*2 <= x && x < frame_size.width*3 ) x -= frame_size.width*2;
			point.x = x;
			point.y = y;
			
			// for debug
			// printf("+++++down+++++\n");
		}
		break;

		case CV_EVENT_RBUTTONDOWN: {
			is_display = false;
		}
		break;

	}
}

string i2str( const int i ) {
	stringstream newstr;
	newstr << i;
	return newstr.str();
}

void putText( IplImage* frame, CvPoint point ) {
	CvFont font;
	CvScalar color = CV_RGB( 255, 255, 255 );
	cvInitFont(
		&font,
		CV_FONT_HERSHEY_SIMPLEX,
		0.5,
		0.5
	);

	string str = "(" + i2str(point.x) + ", " 
				     + i2str(point.y) + ")";

	const char* text = str.c_str();

	cvPutText(
		frame,
		text,
		down_point,
		&font,
		color
	);
}

void putCross( IplImage* frame, CvPoint point ) {
	int length = 15;
	CvScalar color = CV_RGB ( 255, 255, 255 );

	cvLine(
		frame,
		cvPoint( point.x-length, point.y ),
		cvPoint( point.x+length*2, point.y ),
		color
	);

	cvLine(
		frame,
		cvPoint( point.x, point.y-length ),
		cvPoint( point.x, point.y+length ),
		color
	);
}
							   
int main( int argc, char** argv ) {
	// Create Windows
	//
	cvNamedWindow( "Three In One", CV_WINDOW_AUTOSIZE );

	//Create a capture
	//
	CvCapture* capture = NULL;
	if ( argc >= 2 ) {
		capture = cvCreateFileCapture( argv[1] );
	} else {
		capture = cvCreateCameraCapture( 0 );
	}

	IplImage* frame = NULL;
	IplImage* frame_half = NULL;
	IplImage* frame_half_gray = NULL;
	IplImage* frame_half_canny = NULL;
	IplImage* frame_three_in_one = NULL;

	// Listen to mouse
	//
	cvSetMouseCallback(
		"Three In One",
		my_mouse_callback,
		(void*) frame_three_in_one
	);

	// Set the frame's size
	//
	double frame_width = cvGetCaptureProperty( capture, CV_CAP_PROP_FRAME_WIDTH );
	double frame_height = cvGetCaptureProperty( capture, CV_CAP_PROP_FRAME_HEIGHT );

	frame_size = cvSize((int)frame_width/2, (int)frame_height/2);

	while ( 1 ) {
		frame = cvQueryFrame( capture );
		frame_half = doPyrDown( frame );

		frame_half_gray = doGray( frame_half );
		frame_half_canny = doCanny( frame_half_gray );

		frame_three_in_one = three_in_one( frame_half, frame_half_gray, frame_half_canny );

		if ( is_display ) {
			putCross(frame_three_in_one, down_point);
			putText(frame_three_in_one, point);
		}

		cvShowImage( "Three In One", frame_three_in_one );
		if ( cvWaitKey(33) == 27 ) {
			break;
		} else {
			cvReleaseImage( &frame_half );
			cvReleaseImage( &frame_half_gray );
			cvReleaseImage( &frame_half_canny );
			cvReleaseImage( &frame_three_in_one );
		}
	}

	cvReleaseImage( &frame );
	cvReleaseImage( &frame_half );
	cvReleaseImage( &frame_half_gray );
	cvReleaseImage( &frame_half_canny );
	cvReleaseImage( &frame_three_in_one );

	cvReleaseCapture( &capture );

	cvDestroyWindow( "Three In One" );

	return ( 0 );
}

