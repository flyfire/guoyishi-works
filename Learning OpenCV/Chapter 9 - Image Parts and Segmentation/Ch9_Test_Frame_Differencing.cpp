//////////////////////////////////////////////
// Date:       2010-01-12
// Author:     Yishi Guo
// Chapter:    9 Image Parts and Segmentation
// Page:       270p
// Functions:  cvAbsDiff, cvThreshold
//////////////////////////////////////////////
#include "cv.h"
#include "highgui.h"

int main( int argc, char** argv ) {
	CvCapture *capture;
	if ( argc > 1 ) {
		capture = cvCreateFileCapture( argv[1] );
	} else {
		capture = cvCreateCameraCapture( 0 );
	}

	cvNamedWindow( "Frame Differencing", CV_WINDOW_AUTOSIZE );
	// cvNamedWindow( "Test1", CV_WINDOW_AUTOSIZE );
	// cvNamedWindow( "Test2", CV_WINDOW_AUTOSIZE );
	IplImage *frame;
	IplImage *preFrame;
	IplImage *frameForeground = NULL;
	
	// Get the first frame of the capture
	if ( cvGrabFrame( capture ) ) {
		frame = cvQueryFrame( capture );
		preFrame = cvCreateImage(
			                     cvSize( frame->width, frame->height ),
								 frame->depth,
								 frame->nChannels
								);
		cvCopy( frame, preFrame );
		frameForeground = cvCreateImage(
			                            cvSize( preFrame->width, preFrame->height ),
										preFrame->depth,
										preFrame->nChannels
									   );
	} else {
		return -1;
	}

	// Show frame of the capture
	while ( cvGrabFrame( capture ) ) {
		frame = cvQueryFrame( capture );

		cvAbsDiff( frame, preFrame, frameForeground );
		cvThreshold( frameForeground, frameForeground, 50, 255, CV_THRESH_BINARY );

		cvShowImage( "Frame Differencing", frameForeground );

		// For test
		// cvShowImage( "Test1", frame );
		// cvShowImage( "Test2", preFrame );

		if ( cvWaitKey( 33 ) == 27 ) {
			break;
		}

		cvCopy( frame, preFrame );
	}

	cvReleaseImage( &frame );
	cvReleaseImage( &preFrame );
	cvReleaseImage( &frameForeground );
	cvReleaseCapture( &capture );
	cvDestroyWindow( "Frame Differencing" );
	// cvDestroyWindow( "Test1" );
	// cvDestroyWindow( "Test2" );

	return 0;
}