////////////////////////////////////////////////////////////////
// Date:      2009-09-30
// Coder:     Yishi Guo
// Chapter:   6
// Page:      146
// Content:   cvCopyMakeBorder | Convolution Boudaries
////////////////////////////////////////////////////////////////
#include "cv.h"
#include "highgui.h"

int main( int argc, char** argv ) {
	if ( argc >= 2 ) {
		IplImage* src = cvLoadImage( argv[1] );
		IplImage* dst1 = cvCreateImage(
			cvSize( src->width + 20, src->height + 20 ),
			src->depth,
			src->nChannels
			);
		IplImage* dst2 = cvCreateImage(
			cvSize( src->width + 40, src->height + 10 ),
			src->depth,
			src->nChannels
			);

		cvCopyMakeBorder(
			src,
			dst1,
			cvPoint(10, 10),
			IPL_BORDER_CONSTANT,
			cvScalarAll(123)
			);
		cvCopyMakeBorder(
			src,
			dst2,
			cvPoint(20, 5),
			IPL_BORDER_REPLICATE,
			cvScalarAll(0)
			);

		cvNamedWindow( "src", CV_WINDOW_AUTOSIZE );
		cvNamedWindow( "dst1", CV_WINDOW_AUTOSIZE );
		cvNamedWindow( "dst2", CV_WINDOW_AUTOSIZE );

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