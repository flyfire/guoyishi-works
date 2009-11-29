//////////////////////////////////////
// Date:      2009-11-02
// Author:    Yishi Guo
// Exercise:  5-11 
// Chapter:   5 Image Processing
// Page:      143p
// Content:   cvPyrSegmentation()
//////////////////////////////////////
#include "cv.h"
#include "highgui.h"

int main( int argc, char** argv ) {
	if ( argc < 2 ) {
		return -1;
	} else {
		IplImage* src = cvLoadImage( argv[1], CV_LOAD_IMAGE_COLOR );
		if ( !src ) {
			return -1;
		}

		cvNamedWindow( "Exercise 5-11 src", CV_WINDOW_AUTOSIZE );
		cvShowImage( "Exercise 5-11 src", src );

		IplImage* dst = cvCreateImage( cvGetSize(src), src->depth, src->nChannels );

		CvMemStorage* storage = cvCreateMemStorage(0);
		CvSeq* comp = NULL;

		// "Use cvPyrSegmentation() and display the results."
		//
		cvPyrSegmentation( src, dst, storage, &comp, 4, 200, 50 );
		
		cvNamedWindow( "Exercise 5-11 dst", CV_WINDOW_AUTOSIZE );
		cvShowImage( "Exercise 5-11 dst", dst );

		cvWaitKey(0);

		cvReleaseMemStorage( &storage );
		cvReleaseImage( &src );
		cvReleaseImage( &dst );
		cvDestroyWindow( "Exercise 5-11 src" );
		cvDestroyWindow( "Exercise 5-11 dst" );
	}
	return 0;
}