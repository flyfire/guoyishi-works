///////////////////////////////////////////////////////
// Date:      2009-10-19
// Author:    Yishi Guo
// Exercise:  5.4
// Chapter:   5 - Image Processing
// Page:      141p
// Content:   cvAbsDiff, cvErode, cvDilate
///////////////////////////////////////////////////////
#include <iostream.h>
#include "cv.h"
#include "highgui.h"

int main( int argc, char** argv ) {
	if ( argc >= 3 ) {
		IplImage* src1 = cvLoadImage( argv[1] );
		IplImage* src2 = cvLoadImage( argv[2] );

		if ( !src1 || !src2 ) {
			return -1;
		}

		// Part A:
		//
		IplImage* diff12 = cvCreateImage( 
			cvSize(src1->width, src1->height), 
			src1->depth, 
			src1->nChannels 
		);
		cvAbsDiff( src1, src2, diff12 );

		cvNamedWindow( "Exercise 5-4", CV_WINDOW_AUTOSIZE );
		cvShowImage( "Exercise 5-4", diff12 );

		// Part B:
		//
		IplImage* cleandiff = cvCreateImage(
			cvSize( diff12->width, diff12->height ),
			diff12->depth,
			diff12->nChannels
		);

		cvErode( diff12, cleandiff );
		cvDilate( cleandiff, cleandiff );

		cvNamedWindow( "Exercise 5-4 cleandiff", CV_WINDOW_AUTOSIZE );
		cvShowImage( "Exercise 5-4 cleandiff", cleandiff );

		// Part C:
		//
		IplImage* dirtydiff = cvCreateImage(
			cvSize( diff12->width, diff12->height ),
			diff12->depth,
			diff12->nChannels
		);

		cvDilate( diff12, dirtydiff );
		cvErode( dirtydiff, dirtydiff );

		cvNamedWindow( "Exercise 5-4 dirtydiff", CV_WINDOW_AUTOSIZE );
		cvShowImage( "Exercise 5-4 dirtydiff", dirtydiff );

		cvWaitKey(0);

		cvReleaseImage( &src1 );
		cvReleaseImage( &src2 );
		cvReleaseImage( &diff12 );
		cvReleaseImage( &cleandiff );
		cvReleaseImage( &dirtydiff );

		cvDestroyWindow( "Exercise 5-4" );
		cvDestroyWindow( "Exercise 5-4 cleandiff" );
		cvDestroyWindow( "Exercise 5-4 dirtydiff" );

		return 0;
	}
	return -1;
}

