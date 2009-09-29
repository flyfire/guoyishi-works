/////////////////////////////
// Page: 107
// Exercises: Chapter 4 - 1.a
// Creator: Yishi Guo
// Date: 2009.09.13
/////////////////////////////
#include <cv.h>
#include <highgui.h>

int main(int argc, char** argv) {
	// Create Windows
	cvNamedWindow( "Original Frame", CV_WINDOW_AUTOSIZE );
	cvNamedWindow( "Gray Frame", CV_WINDOW_AUTOSIZE );
	cvNamedWindow( "Canny Frame", CV_WINDOW_AUTOSIZE );

	// Create a capture
	//
	CvCapture* capture = NULL;
	if (argc >= 2) {
		capture = cvCreateFileCapture( argv[1] );
	} else {
		capture = cvCreateCameraCapture( 0 );
	}

	////////////////////////////////////
	IplImage* frame = NULL;
	IplImage* frame_gray = NULL;
	IplImage* frame_canny = NULL;
	while ( 1 ) {
		// Original
		frame = cvQueryFrame( capture );
		cvShowImage( "Original Frame", frame );

		// Gray
		frame_gray = cvCreateImage( cvSize( frame->width, frame->height ), frame->depth, 1 );
		cvCvtColor( frame, frame_gray, CV_RGB2GRAY );
		
		cvSmooth( frame_gray, frame_gray, CV_GAUSSIAN, 5);
		cvShowImage( "Gray Frame", frame_gray );

		// Canny
		frame_canny = cvCreateImage( cvSize( frame->width, frame->height ), frame->depth, 1 );
		cvCanny ( frame_gray, frame_canny, 10, 100, 3 );
		cvShowImage( "Canny Frame", frame_canny );

		if ( cvWaitKey(10) == 27 ) {
			break;
		}
		cvReleaseImage( &frame_gray );
		cvReleaseImage( &frame_canny );
	}

	cvReleaseImage( &frame );
	cvReleaseImage( &frame_gray );
	cvReleaseImage( &frame_canny );
	cvReleaseCapture( &capture );
	cvDestroyWindow( "Original Frame" );
	cvDestroyWindow( "Gray Frame" );
	cvDestroyWindow( "Canny Frame" );

	return ( 0 );
}