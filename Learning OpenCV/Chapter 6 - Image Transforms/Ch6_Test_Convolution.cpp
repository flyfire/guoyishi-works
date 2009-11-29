////////////////////////////////////////////
// Date:     2009-11-05
// Author:   Yishi Guo
// Chapter:  6 Image Transforms
// Content:  cvFilter2D
////////////////////////////////////////////
#include "cv.h"
#include "highgui.h"
#include <iostream.h>

void output_mat( CvMat* mat ) {
	int rows = mat->rows;
	int cols = mat->cols;
	int i, j;
	for ( i = 0; i < rows; ++i ) {
		for ( j = 0; j < cols; ++j ) {
			cout << cvmGet( mat, i, j ) << " ";
		}
		cout << endl;
	}
}

int main( int argc, char** argv ) {
	if ( argc < 2 ) {
		return -1;
	} else {
		// Get Martix of Kernel
		//
		CvMat *kernel = cvCreateMat( 3, 3, CV_32FC1 );
		cvZero( kernel );
		
		// For debug
		// output_mat( kernel );

		cvmSet( kernel, 1, 0, 1 );
		cvmSet( kernel, 1, 2, -1);

		// For debug
		// output_mat( kernel );

		// Get Image
		//
		IplImage* src = cvLoadImage( argv[1], CV_LOAD_IMAGE_GRAYSCALE );
		if ( !src ) {
			return -1;
		}
		IplImage* dst = cvCreateImage( cvGetSize(src), src->depth, src->nChannels );

		cvFilter2D( src, dst, kernel );

		const char* src_window_name = "Ch6 Test Convolution src";
		const char* dst_window_name = "Ch6 Test Convolution dst";

		cvNamedWindow( src_window_name, CV_WINDOW_AUTOSIZE );
		cvNamedWindow( dst_window_name, CV_WINDOW_AUTOSIZE );

		cvShowImage( src_window_name, src );
		cvShowImage( dst_window_name, dst );

		cvWaitKey(0);

		cvReleaseMat( &kernel );
		cvReleaseImage( &src );
		cvReleaseImage( &dst );
		cvDestroyWindow( src_window_name );
		cvDestroyWindow( dst_window_name );
	}
	return 0;
}