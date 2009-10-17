/////////////////////////////////////////////////////////////////
// Date:      2009-10-16
// Author:    Yishi Guo
// Exercise:  3.7
// Page:      88
// Content:   Create a mask using cvCmp
//            cvSplit, cvCloneImage, cvMinMaxLoc, cvSet,
//            cvSetZero, cvCmp, cvSubS
/////////////////////////////////////////////////////////////////
#include <cv.h>
#include <highgui.h>
#include <iostream.h>

int main( int argc, char** argv ) {
	if ( argc >= 2 ) {
		IplImage* img = cvLoadImage( argv[1] );
		IplImage* img_red = cvCreateImage( cvGetSize(img), img->depth, 1 );
		IplImage* img_green = cvCreateImage( cvGetSize(img), img->depth, 1 );
		IplImage* img_blue = cvCreateImage( cvGetSize(img), img->depth, 1 );

		IplImage* clone1 = NULL;
		IplImage* clone2 = NULL;

		double min, max;

		// For debug
		// cout << "Channels: " << img->nChannels << endl;

		// Part-A:
		//
		cvSplit( img, img_red, img_green, img_blue, 0 );

		// Part-B:
		//
		clone1 = cvCloneImage( img_green );
		clone2 = cvCloneImage( img_green );

		// Part-C:
		//
		cvMinMaxLoc( img_green, &min, &max );
		// For debug
		cout << "Max: " << max << " Min: " << min << endl;

		// Part-D:
		//
		uchar thresh = (unsigned char)((max - min)/2.0);
		cvSet( clone1, cvScalarAll(thresh) );

		// Part-E:
		//
		cvSetZero( clone2 );
		cvCmp( img_green, clone1, clone2, CV_CMP_GE );

		// Part-F:
		cvSubS( img_green, cvScalarAll(thresh/2), img_green, clone2 );

		cvNamedWindow( "Exercise 3-7 Green", CV_WINDOW_AUTOSIZE );
		cvShowImage( "Exercise 3-7 Green", img_green );

		cvWaitKey(0);

		cvReleaseImage( &img );
		cvReleaseImage( &img_red );
		cvReleaseImage( &img_green );
		cvReleaseImage( &img_blue );

		cvDestroyWindow( "Exercise 3-7 Green" );

		return 0;
	}
	return -1;
}