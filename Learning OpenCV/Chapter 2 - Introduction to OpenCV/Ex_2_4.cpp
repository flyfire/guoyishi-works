#include "cv.h"
#include "highgui.h"

void example2_4( IplImage* image ) {
	// Create some windows to show the input
	// and output images in.
	//
	cvNamedWindow( "Example4-in" );
	cvNamedWindow( "Example4-out" );

	// Create a window to show our input image
	//
	cvShowImage( "Example4-in", image );

	// Create an image to hold the smoothed output
	//
	IplImage* out = cvCreateImage(
		cvGetSize(image),
		IPL_DEPTH_8U,
		3
	);

	// Do the smoothing
	//
	cvSmooth( image, out, CV_GAUSSIAN, 45, 3 );

	// Show the smoothed image in the output window
	//
	cvShowImage( "Example4-out", out );

	// Be tidy
	//
	cvReleaseImage( &out );

	// Wait for the user to hit a key, then clean up the windows
	//
	cvWaitKey( 0 );
	cvDestroyWindow( "Example4-in" );
	cvDestroyWindow( "Example4-out" );
}

int main( int argc, char** argv ) {
	IplImage* img = cvLoadImage( argv[1] );
	example2_4( img );
	cvReleaseImage( &img );
}
