////////////////////////////////////////////////////
// Date:      2009-11-01
// Author:    Yishi Guo
// Exercise:  5-10
// Chapter:   5 Image Processing
// Page:      142p
// Content:   cvResize() VS cvPyrDown()
////////////////////////////////////////////////////
#include "cv.h"
#include "highgui.h"

#define RESIZE_TIMES 3

bool is_can_be_resize( IplImage* img ) {
	int width = img->width;
	int height = img->height;

	int i;
	for ( i = 0; i < RESIZE_TIMES; ++i ) {
		if ( width%2 || height % 2 ) {
			return false;
		} else {
			width /= 2;
			height /= 2;
		}
	}
	return true;
}


IplImage* get_resize_image( IplImage* img, bool is_pyr = false ) {
	IplImage* src = cvCloneImage( img );

	IplImage **resize_img = new IplImage*[RESIZE_TIMES];
	int i;
	int width = src->width;
	int height = src->height;

	for ( i = 0; i < RESIZE_TIMES; ++i ) {
		width /= 2;
		height /= 2;

		resize_img[i] = cvCreateImage( cvSize(width, height), src->depth, src->nChannels );
		if ( is_pyr ) {
			if ( i == 0 ) {
				cvPyrDown( src, resize_img[i] );
			} else {
				cvPyrDown( resize_img[i-1], resize_img[i] );
			}
		} else {
			if ( i == 0 ) {
				cvResize( src, resize_img[i] );
			} else {
				cvResize( resize_img[i-1], resize_img[i] );
			}
		}
	}
	
	cvReleaseImage( &src );

	return resize_img[i-1];
}

int main( int argc, char** argv ) {
	if ( argc < 2 ) {
		return -1;
	} else {
		IplImage* src = cvLoadImage( argv[1] );
		if ( !src ) {
			return -1;
		}

		if ( !is_can_be_resize(src) ) {
			return -2;
		}

		cvNamedWindow( "Exercise 5-10", CV_WINDOW_AUTOSIZE );
		cvShowImage( "Exercise 5-10", src );

		// Part A:
		//
		IplImage* dst1 = get_resize_image( src, false );

		cvNamedWindow( "Exercise 5-10 cvResize()", CV_WINDOW_AUTOSIZE );
		cvShowImage( "Exercise 5-10 cvResize()", dst1 );

		// Part B:
		//
		IplImage* dst2 = get_resize_image( src, true );

		cvNamedWindow( "Exercise 5-10 cvPyrDown()", CV_WINDOW_AUTOSIZE );
		cvShowImage( "Exercise 5-10 cvPyrDown()", dst2 );

		cvWaitKey(0);

		cvReleaseImage( &src );
		cvReleaseImage( &dst1 );
		cvReleaseImage( &dst2 );
		cvDestroyWindow( "Exercise 5-10" );
		cvDestroyWindow( "Exercise 5-10 cvResize()" );
		cvDestroyWindow( "Exercise 5-10 cvPyrDown()" );

	}
	return 0;
}
