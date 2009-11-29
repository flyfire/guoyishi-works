///////////////////////////////////////////////////////
// Date: 2009-11-01
// Author: Yishi Guo
// Exercise: 5.9
// Chapter: 5 Image Processing
// Page: 142p
// Content: Morphological Top Hat Operation

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

		cvWaitKey(0);

		cvReleaseImage( &src );
		cvReleaseImage( &img_a );

		cvDestroyWindow( "Exercise_5_9 src" );
		cvDestroyWindow( "Exercise_5_9 img A" );
	}
	return -1;
}
