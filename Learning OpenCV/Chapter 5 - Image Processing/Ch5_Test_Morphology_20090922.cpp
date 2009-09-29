/////////////////////////////
// Date: 2009-09-22
// Author: Yishi Guo
// Chapter: 5
// Page: 115
// Content: Image Morphology
/////////////////////////////
#include <cv.h>
#include <highgui.h>

int main( int argc, char** argv ) {
	if ( argc >= 2 ) {
		// Create Windows
		//
		cvNamedWindow( "img original", CV_WINDOW_AUTOSIZE );
		cvNamedWindow( "dst1 cvErode", CV_WINDOW_AUTOSIZE );
		cvNamedWindow( "dst2 cvDilate", CV_WINDOW_AUTOSIZE );

		// Prepare the Images
		//
		IplImage* img = cvLoadImage( argv[1] );
		IplImage* dst1 = cvCreateImage(
			cvSize( img->width, img->height ),
			img->depth,
			img->nChannels
			);
		IplImage* dst2 = cvCloneImage( dst1 );

		// Make Move on the Destinations
		//
		cvErode(
			img,
			dst1,
			NULL,
			1
			);

		cvDilate(
			img,
			dst2,
			NULL,
			1
			);

		// Show Images
		//
		cvShowImage( "img original", img );
		cvShowImage( "dst1 cvErode", dst1 );
		cvShowImage( "dst2 cvDilate", dst2 );

		cvWaitKey( 0 );

		// Release Resourses
		//
		cvReleaseImage( &img );
		cvReleaseImage( &dst1 );
		cvReleaseImage( &dst2 );

		cvDestroyWindow( "img original" );
		cvDestroyWindow( "dst1 cvErode" );
		cvDestroyWindow( "dst2 cvDilate" );
	}

	return 0;
}
