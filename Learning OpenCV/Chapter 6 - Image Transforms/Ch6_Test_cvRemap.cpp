///////////////////
// ERROR!
// 2009-10-03
///////////////////
#include "cv.h"
#include "highgui.h"

int main( int argc, char** argv ) {
	if ( argc >= 2 ) {
		IplImage* src = cvLoadImage( argv[1] );
		IplImage* dst = cvCreateImage( cvGetSize(src), src->depth, src->nChannels );
		IplImage* mapx = cvCreateImage( cvGetSize(src), IPL_DEPTH_32F, src->nChannels );
		IplImage* mapy = cvCreateImage( cvGetSize(src), IPL_DEPTH_32F, src->nChannels );

		cvRemap(
			src,
			dst,
			mapx,
			mapy,
			CV_INTER_LINEAR + CV_WARP_FILL_OUTLIERS,
			cvScalarAll(0)
			);

		cvNamedWindow( "src", CV_WINDOW_AUTOSIZE );
		cvNamedWindow( "dst", CV_WINDOW_AUTOSIZE );

		cvShowImage( "src", src );
		cvShowImage( "dst", dst );

		cvWaitKey( 0 );

		cvReleaseImage( &src );
		cvReleaseImage( &dst );
		cvReleaseImage( &mapx );
		cvReleaseImage( &mapy );

		cvDestroyWindow( "src" );
		cvDestroyWindow( "dst" );
	}

	return 0;
}
