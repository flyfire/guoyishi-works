#include "cv.h"
#include "highgui.h"

IplImage* doPyrDown(
	IplImage* in,
	int       filter = IPL_GAUSSIAN_5x5
	) {
	// Best to make sure input image is divisible by two.
	//
	assert( in->width%2 == 0 && in->height%2 == 0 );

	IplImage* out = cvCreateImage(
		cvSize( in->width/2, in->height/2 ),
		in->depth,
		in->nChannels
	);
	cvPyrDown( in, out );
	return( out );
};

int main(int argc, char** argv ) {
	IplImage* img = cvLoadImage( argv[1] );
	cvNamedWindow( "Example5", CV_WINDOW_AUTOSIZE );
	cvShowImage( "Example5", img );
	IplImage* out = doPyrDown( img );
	cvNamedWindow( "Example5-out", CV_WINDOW_AUTOSIZE );
	cvShowImage( "Example5-out", out );
	cvWaitKey( 0 );

	cvReleaseImage( &img );
	cvReleaseImage( &out );
	cvDestroyWindow( "Example5" );
	cvDestroyWindow( "Example5-out" );
}
	
