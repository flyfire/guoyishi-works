/////////////////////////////////////////////////
// Date:       2009-10-04
// Coder:      Yishi Guo
// Copy From:  Example 6-4
// Chapter:    6
// Page:       176
// Content:    LogPolar | Image Transforms
/////////////////////////////////////////////////
#include <cv.h>
#include <highgui.h>

int main( int argc, char** argv ) {
	IplImage *src;
	double M;
	if ( argc == 3 && ((src = cvLoadImage(argv[1], 1)) != 0 )) {
		M = atof(argv[2]);
		IplImage* dst = cvCreateImage( cvGetSize(src), 8, 3 );
		IplImage* src2 = cvCreateImage( cvGetSize(src), 8, 3 );

		cvLogPolar(
			src,
			dst,
			cvPoint2D32f(src->width/2, src->height/2),
			M,
			CV_INTER_LINEAR + CV_WARP_FILL_OUTLIERS
			);

		cvLogPolar(
			dst,
			src2,
			cvPoint2D32f(src->width/2, src->height/2),
			M,
			CV_INTER_LINEAR | CV_WARP_INVERSE_MAP
			);

		cvNamedWindow( "log-polar", CV_WINDOW_AUTOSIZE );
		cvShowImage( "log-polar", dst );
		cvNamedWindow( "inverse log-polar", 1 );
		cvShowImage( "inverse log-polar", src2 );
		cvWaitKey( 0 );

		cvReleaseImage( &src );
		cvReleaseImage( &src2 );
		cvReleaseImage( &dst );
		cvDestroyWindow( "log-polar" );
		cvDestroyWindow( "inverse log-polar" );
	}
	return 0;
}