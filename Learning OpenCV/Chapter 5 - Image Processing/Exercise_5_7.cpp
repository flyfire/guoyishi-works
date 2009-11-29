//////////////////////////////////////////////
// Date:      2009-10-29
// Author:    Yishi Guo
// Exercise:  5.7
// Chapter:   5 Image Processing
// Page:      142p
// Content:   cvCopy( src, dst, mask );
//////////////////////////////////////////////
#include "cv.h"
#include "highgui.h"
#include <iostream.h>

int main( int argc, char** argv ) {
	if( argc < 3 ) {
		return -1;
	} else {
		IplImage* src = cvLoadImage( argv[1], CV_LOAD_IMAGE_COLOR );
		IplImage* mask_src = cvLoadImage( argv[2], CV_LOAD_IMAGE_GRAYSCALE );
		if( !src || !mask_src ) {
			return -1;
		}

		// Get colorized mask
		//
		IplImage* mask_src_color = cvCreateImage( cvGetSize(mask_src), IPL_DEPTH_8U, 3 );
		cvCvtColor( mask_src, mask_src_color, CV_GRAY2RGB );

		// Show Images
		//

		cvNamedWindow( "src", CV_WINDOW_AUTOSIZE );
		cvNamedWindow( "mask", CV_WINDOW_AUTOSIZE );

		cvShowImage( "src", src );
		cvShowImage( "mask", mask_src_color );

		// For Test
		IplImage* img = cvCreateImage( cvGetSize(src), src->depth, src->nChannels );
		// IplImage* img;  // This could not be used!

		// Resize mask
		//
		IplImage* mask = cvCreateImage( cvGetSize(src), IPL_DEPTH_8U, 1 );		
		cvResize( mask_src, mask, CV_INTER_CUBIC );

		// Threshold the mask image
		//
		if( argc > 3 ) {
			double threshold = atof( argv[3] );
			cvThreshold( mask, mask, threshold, 255, CV_THRESH_BINARY );
		}

		cvCopy( src, img, mask );

		cvNamedWindow( "Exercise 5-7", CV_WINDOW_AUTOSIZE );
		cvShowImage( "Exercise 5-7", img );

		cvWaitKey(0);

		cvReleaseImage( &src );
		cvReleaseImage( &mask );
		cvReleaseImage( &img );
		cvReleaseImage( &mask_src );
		cvReleaseImage( &mask_src_color );

		cvDestroyWindow( "src" );
		cvDestroyWindow( "mask" );
		cvDestroyWindow( "Exercise 5-7" );
	}
	return 0;
}