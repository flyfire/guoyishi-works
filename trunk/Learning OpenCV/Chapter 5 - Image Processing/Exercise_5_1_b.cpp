///////////////////////////////////////
// Date:       2009-09-26
// Author:     Yishi Guo
// Chapter:    5
// Exercise:   5.2.a
// Content:    Compare the two filters
///////////////////////////////////////
#include <iostream.h>
#include "cv.h"
#include "highgui.h"

int main( int argc, char** argv ) {
	if ( argc >= 2 ) {
		IplImage* src = cvLoadImage( argv[1] );
		IplImage* dst1 = cvCreateImage( cvGetSize(src), src->depth, src->nChannels );
		IplImage* dst2 = cvCreateImage( cvGetSize(src), src->depth, src->nChannels );

		cvNamedWindow( "src", CV_WINDOW_AUTOSIZE );
		cvNamedWindow( "dst1", CV_WINDOW_AUTOSIZE );
		cvNamedWindow( "dst2", CV_WINDOW_AUTOSIZE );

		cvSmooth( src, dst1, CV_GAUSSIAN, 5, 5 );
		cvSmooth( dst1, dst1, CV_GAUSSIAN, 5, 5 );

		cvSmooth( src, dst2, CV_GAUSSIAN, 11, 11 );

		cvShowImage( "src", src );
		cvShowImage( "dst1", dst1 );
		cvShowImage( "dst2", dst2 );

		cvWaitKey();

		cvReleaseImage( &src );
		cvReleaseImage( &dst1 );
		cvReleaseImage( &dst2 );

		cvDestroyWindow( "src" );
		cvDestroyWindow( "dst1" );
		cvDestroyWindow( "dst2" );
	}
	return 0;
}
