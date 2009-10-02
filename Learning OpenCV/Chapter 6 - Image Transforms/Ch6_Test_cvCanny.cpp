//////////////////////////////////////////////
// Date:     2009-10-01
// Author:   Yishi Guo
// Chapter:  6
// Page:     152
// Content:  Canny | Image Transforms
//////////////////////////////////////////////
#include <iostream>
#include "cv.h"
#include "highgui.h"

int main ( int argc, char** argv ) {
	if ( argc >= 2 ) {
		// Get images
		//
		IplImage* src_gray = cvLoadImage( argv[1], CV_LOAD_IMAGE_GRAYSCALE );
		IplImage* dst_canny = cvCreateImage( cvGetSize(src_gray), src_gray->depth, src_gray->nChannels );

		// Create windows
		// 
		cvNamedWindow( "src", CV_WINDOW_AUTOSIZE );
		cvNamedWindow( "dst", CV_WINDOW_AUTOSIZE );

		// Canny
		// 
		if ( argc >= 4 ) {  // If the user input the lowThresh and highThresh
			                // then use them
			cvCanny( src_gray, dst_canny, atoi(argv[2]), atoi(argv[3]), 3 );
		} else {
			cvCanny( src_gray, dst_canny, 100, 200, 3 );
		}

		// Show images
		// 
		cvShowImage( "src", src_gray );
		cvShowImage( "dst", dst_canny );

		// Wait for a key
		// 
		cvWaitKey();

		// Clear resources
		// 
		cvReleaseImage( &src_gray );
		cvReleaseImage( &dst_canny );

		cvDestroyWindow( "src" );
		cvDestroyWindow( "dst" );
	}
	return 0;
}