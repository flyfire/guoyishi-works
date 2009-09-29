///////////////////////////////////////////////////
// Date:       2009-09-26
// Author:     Yishi Guo
// Chapter:    5
// Page:       141
// Exercise:   5.3
// Content:    param1 / param2 / param3 / param4
///////////////////////////////////////////////////
#include <iostream.h>
#include "cv.h"
#include "highgui.h"

int main( int argc, char** argv ) {
	if ( argc >= 2 ) {
		IplImage* src = cvLoadImage( argv[1] );
		IplImage* dst_a = cvCreateImage( cvGetSize(src), src->depth, src->nChannels );
		IplImage* dst_b = cvCloneImage( dst_a );
		IplImage* dst_c = cvCloneImage( dst_a );
		IplImage* dst_d = cvCloneImage( dst_a );
		IplImage* dst_e = cvCloneImage( dst_a );
		IplImage* dst_f = cvCloneImage( dst_a );

		cvNamedWindow( "src" );
		cvNamedWindow( "dst a" );
		cvNamedWindow( "dst b" );
		cvNamedWindow( "dst c" );
		cvNamedWindow( "dst d" );
		cvNamedWindow( "dst e" );
		cvNamedWindow( "dst f" );

		cvShowImage( "src", src );

		int param3 = 0;
		bool change = false;

		for( param3 = 0, change = false; param3 <= 30; param3 += 2 ) {
			cvSmooth( src, dst_a, CV_GAUSSIAN, 9, 9, param3 );
			cvSmooth( src, dst_b, CV_GAUSSIAN, 1, 0, param3 );
			cvSmooth( src, dst_c, CV_GAUSSIAN, 1, 0, 1, 9 );
			cvSmooth( src, dst_d, CV_GAUSSIAN, 1, 0, 9, 1 );
			cvSmooth( src, dst_e, CV_GAUSSIAN, 1, 0, 1, 9 );
			cvSmooth( dst_e, dst_e, CV_GAUSSIAN, 1, 0, 9, 1 );
			if (change) {
				cvSmooth( src, dst_f, CV_GAUSSIAN, 1, 0, 9, 9 );
			} else {
				cvSmooth( src, dst_f, CV_GAUSSIAN, 1, 0, 0, 0 );
			}

			cvShowImage( "dst a", dst_a );
			cvShowImage( "dst b", dst_b );
			cvShowImage( "dst c", dst_c );
			cvShowImage( "dst d", dst_d );
			cvShowImage( "dst e", dst_e );
			cvShowImage( "dst f", dst_f );

			cout << "a: param3=" << param3 << endl;
			if ( cvWaitKey() == 27 ) break;
			if ( param3 == 30 ) param3 = 0;
			if ( change == false ) {
				change = true;
			} else {
				change = false;
			}
		}

		cvReleaseImage( &src );
		cvReleaseImage( &dst_a );
		cvReleaseImage( &dst_b );
		cvReleaseImage( &dst_c );
		cvReleaseImage( &dst_d );
		cvReleaseImage( &dst_e );
		cvReleaseImage( &dst_f );

		cvDestroyWindow( "src" );
		cvDestroyWindow( "dst a" );
		cvDestroyWindow( "dst b" );
		cvDestroyWindow( "dst c" );
		cvDestroyWindow( "dst d" );
		cvDestroyWindow( "dst e" );
		cvDestroyWindow( "dst f" );
	}
	return 0;
}