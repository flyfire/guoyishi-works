#include "cv.h"
#include "highgui.h"

IplImage* doCanny(
	IplImage* in,
	double lowThresh,
	double highThresh,
	double aperture
	) {
	if (in->nChannels != 1)
		return (0); // Canny only handles gray scale images
	IplImage* out = cvCreateImage(
		cvGetSize( in ),
		IPL_DEPTH_8U,
		1
	);
	cvCanny( in, out, lowThresh, highThresh, aperture );
	return ( out );
};

int main( int argc, char** argv ) {
	/*
	IplImage* img = cvLoadImage( argv[1] );
	cvNamedWindow( "Example6", CV_WINDOW_AUTOSIZE );
	cvShowImage( "Example6", img );

	IplImage* out = doCanny( img, 10, 100, 3 );
	cvNamedWindow( "Example6-out", CV_WINDOW_AUTOSIZE );
	cvShowImage( "Example6-out", out );

	cvWaitKey( 0 );
	cvReleaseImage( &img );
	cvReleaseImage( &out );
	cvDestroyWindow( "Example6" );
	cvDestroyWindow( "Example6-out" );
	*/
}