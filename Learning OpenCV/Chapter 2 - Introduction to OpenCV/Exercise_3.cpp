#include "cv.h"
#include "highgui.h"

IplImage* doCanny(
	IplImage* in,
	double lowThresh,
	double highThresh,
	double aperture)
{
	IplImage* out = cvCreateImage(
		cvGetSize( in ),
		in->depth,  // IPL_DEPTH_8U
		1);
	cvCanny( in, out, lowThresh, highThresh, aperture );
	return( out );
};

int main (int argc, char** argv) {
	cvNamedWindow( "Exercise_2_3", CV_WINDOW_AUTOSIZE );
	cvNamedWindow( "Exercise_2_3 Gray", CV_WINDOW_AUTOSIZE );
	cvNamedWindow( "Exercise_2_3 Canny", CV_WINDOW_AUTOSIZE );

	CvCapture* capture;
	if (argc == 1) {
		capture = cvCreateCameraCapture( 0 );
	} else {
		capture = cvCreateFileCapture( argv[1] );
	}
	assert( capture != NULL );

	IplImage* frame = 0;
	IplImage* frame_gray = 0;
	IplImage* frame_canny = 0;
	while (1) {
		frame = cvQueryFrame( capture );
		if (!frame) break;
		cvShowImage( "Exercise_2_3", frame );
		
		frame_gray = cvCreateImage( cvSize( frame->width, frame->height ), frame->depth, 1 );
		cvCvtColor(frame, frame_gray, CV_BGR2GRAY);
		cvShowImage( "Exercise_2_3 Gray", frame_gray );

		frame_canny = doCanny( frame_gray, 10, 100, 3 );
		cvShowImage( "Exercise_2_3 Canny", frame_canny );

		char c = cvWaitKey( 100 );
		if ( c == 27 ) break;
		cvReleaseImage( &frame_gray );
		cvReleaseImage( &frame_canny );
	}

	cvReleaseCapture( &capture );
	cvReleaseImage( &frame );
	cvReleaseImage( &frame_gray );
	cvReleaseImage( &frame_canny );

	cvDestroyWindow("Exercise_2_3");
	cvDestroyWindow("Exercise_2_3 Gray");
	cvDestroyWindow("Exercise_2_3 Canny");

	return 0;
}