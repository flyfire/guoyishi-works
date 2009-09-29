////////////////////////////////////////////
// Page: 107
// Exercises: Chapter 4 - 1.b and 1.c
// Creator: Yishi Guo
// Date: 2009.09.13
////////////////////////////////////////////
#include <cv.h>
#include <highgui.h>
#include <stdio.h>

IplImage* doPyrDown( IplImage* in, int filter = IPL_GAUSSIAN_5x5 ) {
	// Best to make sure input image is divisible by two.
	//
	assert( in->width%2 == 0 && in->height%2 == 0);

	IplImage* out = cvCreateImage(
		cvSize( in->width/2, in->height/2 ),
		in->depth,
		in->nChannels
	);
	cvPyrDown( in, out, filter );
	return ( out );
}

IplImage* doGray( IplImage* in ) {
	IplImage* out = cvCreateImage(
		cvSize( in->width, in->height ),
		in->depth,
		1
	);

	cvCvtColor( in, out, CV_RGB2GRAY );

	return out;
}

IplImage* doNotGray( IplImage* in, int nChannels = 3 ) {
	IplImage* out = cvCreateImage(
		cvSize( in->width, in->height ),
		in->depth,
		nChannels
	);

	cvCvtColor( in, out, CV_GRAY2RGB );

	return out;
}

IplImage* doCanny(
	IplImage* in,
	double lowThresh = 10,
	double highThresh = 100,
	double aperture = 3
	){
	if ( in->nChannels != 1 ) {
		return ( 0 );	// Canny only handles gray scale images
	}

	IplImage* out = cvCreateImage(
		cvGetSize( in ),
		in->depth,
		1
	);
	cvCanny( in, out, lowThresh, highThresh, aperture );
	return ( out );
}

int main( int argc, char** argv ) {
	// Create Windows
	//
	cvNamedWindow( "Three In One", CV_WINDOW_AUTOSIZE );
	/*
	cvNamedWindow( "Temp1", CV_WINDOW_AUTOSIZE );
	cvNamedWindow( "Temp2", CV_WINDOW_AUTOSIZE );
	cvNamedWindow( "Temp3", CV_WINDOW_AUTOSIZE );
	cvNamedWindow( "Temp4", CV_WINDOW_AUTOSIZE );
	*/

	// Create a capture
	//
	CvCapture* capture = NULL;
	if ( argc >= 2 ) {
		capture = cvCreateFileCapture( argv[1] );
	} else {
		capture = cvCreateCameraCapture(0);
		// printf("%d", capture);
	}

	//
	IplImage* frame = NULL;
	IplImage* frame_half = NULL;
	IplImage* frame_half_gray = NULL;
	IplImage* frame_half_canny = NULL;
	IplImage* frame_three_in_one = NULL;
	IplImage* frame_half_gray_3_Channel = NULL;
	IplImage* frame_half_canny_3_Channel = NULL;
	
	while ( 1 ) {
		/////////////////
		// Original
		//
		frame = cvQueryFrame( capture );
		// cvShowImage( "Temp1", frame );

		// DownSamples image
		//
		frame_half = doPyrDown( frame );
		// cvShowImage( "Temp2", frame_half );

		// Gray
		//
		frame_half_gray = doGray( frame_half );
		// cvShowImage( "Temp3", frame_half_gray );

		// Canny
		//
		frame_half_canny = doCanny( frame_half_gray );
		// cvShowImage( "Temp4", frame_half_canny );

		/////////////////
		// Three in one
		//
		frame_three_in_one = cvCreateImage( cvSize(frame_half->width * 3, frame_half->height), frame_half->depth, frame_half->nChannels );

		// Add original frame to "Three in one"
		//
		cvSetImageROI(frame_three_in_one, cvRect(0, 0, frame_half->width, frame_half->height));
		cvSetImageROI(frame_half, cvRect(0, 0, frame_half->width, frame_half->height));
		cvCopy(frame_half, frame_three_in_one);
		cvResetImageROI(frame_three_in_one);
		cvResetImageROI(frame_half);

		// Add gray frame to "Three in one"
		//
		cvSetImageROI(frame_three_in_one, cvRect(frame_half->width, 0, frame_half->width, frame_half->height));
		// cvCvtColor(frame_half_gray, frame_half_gray, CV_GRAY2RGB);	//! Could not be use!
		frame_half_gray_3_Channel = doNotGray( frame_half_gray, frame_half->nChannels );
		cvSetImageROI(frame_half_gray_3_Channel, cvRect(0, 0, frame_half->width, frame_half->height));
		cvCopy(frame_half_gray_3_Channel, frame_three_in_one);
		cvResetImageROI(frame_three_in_one);
		cvResetImageROI(frame_half_gray_3_Channel);

		// Add canny frame to "three in one"
		//
		cvSetImageROI(frame_three_in_one, cvRect(frame_half->width * 2, 0, frame_half->width, frame_half->height));
		frame_half_canny_3_Channel = doNotGray( frame_half_canny, frame_half->nChannels );
		cvSetImageROI(frame_half_canny_3_Channel, cvRect(0, 0, frame_half->width, frame_half->height));
		cvCopy(frame_half_canny_3_Channel, frame_three_in_one);
		cvResetImageROI(frame_three_in_one);
		cvResetImageROI(frame_half_canny_3_Channel);

		////////////
		// Add test to the frame
		//
		char* text_origin = "Original";
		char* text_gray = "Gray";
		char* text_canny = "Canny";

		CvFont font;
		CvScalar color = CV_RGB(255, 255, 255);
		cvInitFont(
			&font,
			CV_FONT_HERSHEY_SIMPLEX,
			0.5,
			0.5
		);
		cvPutText(
			frame_three_in_one,
			text_origin,
			cvPoint(0, frame_half->height-5),
			&font,
			color
		);
		cvPutText(
			frame_three_in_one,
			text_gray,
			cvPoint(frame_half->width, frame_half->height-5),
			&font,
			color
		);
		cvPutText(
			frame_three_in_one,
			text_canny,
			cvPoint(frame_half->width*2, frame_half->height-5),
			&font,
			color
		);

		cvShowImage( "Three In One", frame_three_in_one );

		// Judge "Escape"
		//
		if ( cvWaitKey(33) == 27 ) {
			break;
		} else {
			// cvReleaseImage( &frame );
			cvReleaseImage( &frame_half );
			cvReleaseImage( &frame_half_gray );
			cvReleaseImage( &frame_half_canny );
			cvReleaseImage( &frame_three_in_one );
			cvReleaseImage( &frame_half_gray_3_Channel );
			cvReleaseImage( &frame_half_canny_3_Channel );
		}
	}

	cvReleaseImage( &frame );
	cvReleaseImage( &frame_half );
	cvReleaseImage( &frame_half_gray );
	cvReleaseImage( &frame_half_canny );
	cvReleaseImage( &frame_three_in_one );
	cvReleaseImage( &frame_half_gray_3_Channel );
	cvReleaseImage( &frame_half_canny_3_Channel );
	
	cvReleaseCapture( &capture );

	cvDestroyWindow( "Three In One" );
	/*
	cvDestroyWindow( "Temp1" );
	cvDestroyWindow( "Temp2" );
	cvDestroyWindow( "Temp3" );
	cvDestroyWindow( "Temp4" );
	*/

	return ( 0 );
}