//////////////////////////////////////////////////////
// Date:       2009-10-01
// Author:     Yishi Guo
// Chapter:    6
// Content:    cvLaplace | Image Transforms
// Reference:  http://www.opencv.org.cn/forum/viewtopic.php?t=178
//////////////////////////////////////////////////////
#include "cv.h"
#include "highgui.h"

int main( int argc, char** argv ) {
	if ( argc >= 2 ) {
		// Get Images
		//
		IplImage* src = cvLoadImage( argv[1] );
		IplImage* dst = cvCreateImage( cvGetSize(src), IPL_DEPTH_16S, src->nChannels );
		IplImage* dst2 = cvCreateImage( cvGetSize(src), src->depth, src->nChannels );

		// Create Windows
		//
		cvNamedWindow( "src", CV_WINDOW_AUTOSIZE );
		cvNamedWindow( "dst", CV_WINDOW_AUTOSIZE );

		// Make move on the images
		//
		cvLaplace( src, dst, 3 );
		cvConvertScaleAbs( dst, dst2, 1, 0 );

		// Show the images
		//
		cvShowImage( "src", src );
		cvShowImage( "dst", dst2 );

		// Wait a key
		//
		cvWaitKey();

		// Clear Resources
		// 
		cvReleaseImage( &src );
		cvReleaseImage( &dst );
		cvReleaseImage( &dst2 );

		cvDestroyWindow( "src" );
		cvDestroyWindow( "dst" );
	}
	return 0;
}