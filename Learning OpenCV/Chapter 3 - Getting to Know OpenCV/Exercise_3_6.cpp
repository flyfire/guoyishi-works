////////////////////////////////////////////////////////////////////////
// Date:     2009-10-16
// Author:   Yishi Guo
// Exercise: 3.6
// Page:     88
// Content:  Use multiple image headers for one image.
//           cvCreateImageHeader, cvNot, imageData
////////////////////////////////////////////////////////////////////////
#include <cv.h>
#include <highgui.h>
#include <iostream.h>

int main( int argc, char** argv ) {
	if ( argc >= 2 ) {
		IplImage* img = cvLoadImage( argv[1] );

		if ( img->width >= 100 && img->height >= 100 ) {
			IplImage* header1 = cvCreateImageHeader(
				cvGetSize(img),
				img->depth,
				img->nChannels
			);
			IplImage* header2 = cvCreateImageHeader(
				cvGetSize(img),
				img->depth,
				img->nChannels
			);

			header1->origin = header2->origin = img->origin;
			header1->widthStep = header2->widthStep = img->widthStep;

			header1->width = header2->width = 20;
			header1->height = header2->height = 30;

			// Using imageData of "img"
			header1->imageData = img->imageData +
				10 * img->widthStep +
				5 * img->nChannels;
			header2->imageData = img->imageData +
				60 * img->widthStep +
				50 * img->nChannels;

			// Create inverted rectangles
			cvNot( header1, header1 );
			cvNot( header2, header2 );

			cvNamedWindow( "Exercise 3-6", CV_WINDOW_AUTOSIZE );
			cvShowImage( "Exercise 3-6", img );

			cvWaitKey(0);

			cvReleaseImageHeader( &header1 );
			cvReleaseImageHeader( &header2 );
			cvDestroyWindow( "Exercise 3-6" );

		}

		cvReleaseImage( &img );

		return 0;
	}
	return -1;
}
