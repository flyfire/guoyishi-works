#include "highgui.h"
#include "cv.h"



int main( int argc, char** argv ) {
	// Create a named window with the name of the file.
	cvNamedWindow( argv[1], 1 );

	// Load the image from the given file name.
	IplImage* img = cvLoadImage( argv[1] );

	// Show the image in the named window
	cvShowImage( argv[1], img );

	// Idle until the user hits the "Esc" key.
	while ( 1 ) {
		if ( cvWaitKey( 100 ) == 27 ) break;
	}

	// Create a "gray" image
	IplImage* img_gray = cvCreateImage( cvSize( img->width, img->height ), img->depth, 1 );
	cvCvtColor( img, img_gray, CV_BGR2GRAY );

	// Save the gray image to file
	cvSaveImage( argv[2], img_gray );

	// Create a "Canny" image
	IplImage* img_canny = cvCreateImage( cvSize( img->width, img->height ), img->depth, 1 );
	cvCanny( img_gray, img_canny, 10, 100, 3 );

	// Save the gray img to file
	cvSaveImage( argv[3], img_canny );

	// Clean up and don't be piggies
	cvDestroyWindow( argv[1] );
	cvReleaseImage( &img );

	exit(0);
}