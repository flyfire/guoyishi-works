////////////////////////////////////////////////////////////
// Date:      2009-10-29
// Author:    Yishi Guo
// Exercise:  5.8 Part2
// Chapter:   5 Image Processing
// Page:      142p
// Content:   cvSmooth( src, dst, CV_BILATERAL );
////////////////////////////////////////////////////////////
#include "cv.h"
#include "highgui.h"

int main( int argc, char** argv ) {
	if ( argc < 2 ) {
		return -1;
	} else {
		IplImage* src = cvLoadImage( argv[1], CV_LOAD_IMAGE_COLOR );
		if( !src ) {
			return -1;
		}

		cvNamedWindow( "Exercise 5-8 src", CV_WINDOW_AUTOSIZE );
		cvShowImage( "Exercise 5-8 src", src );

		IplImage* img = cvCreateImage( cvGetSize(src), src->depth, src->nChannels );
		cvSmooth( src, img, CV_BILATERAL );

		cvNamedWindow( "Exercise 5-8 img", CV_WINDOW_AUTOSIZE );
		cvShowImage( "Exercise 5-8 img", img );

		// The result is "empty" image
		// Why?

		cvWaitKey(0);

		cvReleaseImage( &src );
		cvReleaseImage( &img);
		cvDestroyWindow( "Exercise 5-8 src" );
		cvDestroyWindow( "Exrecise 5-8 img" );
	}
	return 0;
}