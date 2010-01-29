///////////////////////////////////////////////////////
// Date:      2009-11-01
// Modifid:   2010-01-29
// Author:    Yishi Guo
// Exercise:  5.9
// Chapter:   5 Image Processing
// Page:      142p
// Content:   Morphological Top Hat Operation

#include "cv.h"
#include "highgui.h"

int main( int argc, char** argv ) {
	if ( argc < 2 ) {
		return -1;
	} else {
		IplImage* src = cvLoadImage( argv[1], CV_LOAD_IMAGE_GRAYSCALE );
		if ( !src ) {
			return -1;
		}

		cvNamedWindow( "Exercise_5_9 src", CV_WINDOW_AUTOSIZE );
		cvShowImage( "Exercise_5_9 src", src );

		IplImage* img_a = cvCloneImage( src );

		cvMorphologyEx(
			src,
			img_a,
			NULL,
			NULL,
			CV_MOP_TOPHAT,
			1
		);

		if ( !img_a ) {
			return -1;
		}

		cvNamedWindow( "Exercise_5_9 img A", CV_WINDOW_AUTOSIZE );
		cvShowImage( "Exercise_5_9 img A", img_a );

		/////////////////////
		// 2010-01-29
		// B
		//
		IplImage *img_b = cvCreateImage( cvSize(src->width, src->height), IPL_DEPTH_8U, 1 );
		cvCopy( img_a, img_b );
		cvThreshold( img_b, img_b, 25, 255, CV_THRESH_BINARY );

		cvNamedWindow( "Exercise_5_9 img B", CV_WINDOW_AUTOSIZE );
		cvShowImage( "Exercise_5_9 img B", img_b );

		// C
		IplImage *img_black = cvCreateImage( cvSize(src->width, src->height), IPL_DEPTH_8U, 1 );
		cvZero( img_black );
		IplImage *img_c = cvCreateImage( cvSize(src->width, src->height), IPL_DEPTH_8U, 1 );
		cvSet( img_c, cvScalarAll(200) );

		cvCopy( img_black, img_c, img_b );

		cvNamedWindow( "Exercise_5_9 img C", CV_WINDOW_AUTOSIZE );
		cvShowImage( "Exercise_5_9 img C", img_c );

		cvWaitKey(0);

		cvReleaseImage( &src );
		cvReleaseImage( &img_a );
		cvReleaseImage( &img_b );
		cvReleaseImage( &img_c );

		cvDestroyWindow( "Exercise_5_9 src" );
		cvDestroyWindow( "Exercise_5_9 img A" );
		cvDestroyWindow( "Exercise_5_9 img B" );
		cvDestroyWindow( "Exercise_5_9 img C" );
	}
	return -1;
}
