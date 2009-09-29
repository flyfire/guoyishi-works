/////////////////////////////////////
// Date:       2009-09-26
// Author:     Yishi Guo
// Chapter:    5
// Exercise:   5.1.a
/////////////////////////////////////
#include <iostream.h>
#include <string>
#include "cv.h"
#include "highgui.h"

int main(int argc, char** argv) {
	if (argc >= 2) {
		cvNamedWindow( "src", CV_WINDOW_AUTOSIZE );
		cvNamedWindow( "dst", CV_WINDOW_AUTOSIZE );

		IplImage* src = cvLoadImage( argv[1] );
		IplImage* dst = cvCreateImage( cvGetSize(src), src->depth, src->nChannels );

		cvShowImage( "src", src );
		int size = 3;
		for ( size = 3; size <=33; size += 2 ) {
			cvSmooth( src, dst, CV_GAUSSIAN, size, size );  // different level of smooth

			cvShowImage( "dst", dst );

			if ( cvWaitKey( 0 ) == 27 ) break;

			if (size == 33) size = 3;  // show again
		}

		cvReleaseImage( &src );
		cvReleaseImage( &dst );

		cvDestroyWindow( "src" );
		cvDestroyWindow( "dst" );
	}

	return 0;
}