//////////////////////////////////////////////////////////////
// Date:       2009-09-30
// Author:     Yishi Guo
// Chapter:    6
// Page:       149
// Content:    cvSobel | Gradients and Sobel Derivatives
//////////////////////////////////////////////////////////////
#include "cv.h"
#include "highgui.h"

int main( int argc, char** argv ) {
	if ( argc >= 2 ) {
		// Get images
		// 
		IplImage* src = cvLoadImage( argv[1] );
		IplImage* dst = cvCreateImage(
			cvSize( src->width, src->height ),
			src->depth,
			src->nChannels
			);

		// Do something with the images
		cvSobel(
			src,   // source image
			dst,   // dstination image
			1,     // xorder
			0,     // yorder
			CV_SCHARR      // aperture size
			);

		// Create windows
		cvNamedWindow( "src", CV_WINDOW_AUTOSIZE );
		cvNamedWindow( "dst", CV_WINDOW_AUTOSIZE );

		// Show images
		cvShowImage( "src", src );
		cvShowImage( "dst", dst );

		// Wait key
		cvWaitKey();

		// Clear resources
		cvReleaseImage( &src );
		cvReleaseImage( &dst );

		cvDestroyWindow( "src" );
		cvDestroyWindow( "dst" );
	}

	return 0;
}


