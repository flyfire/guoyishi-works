///////////////////////////////////////////////////////////
// Date:      2009-10-28
// Author:    Yishi Guo
// Exercise:  5.5
// Chapter:   5 Image Processing
// Page:      142p
// Content:   cvAbsDiff, cvThreshold, cvMorphologyEx
///////////////////////////////////////////////////////////
#include "cv.h"
#include "highgui.h"

int main( int argc, char** argv ) {
	if ( argc < 3 ) {
		return -1;
	} else {
		IplImage* img1 = cvLoadImage( argv[1], CV_LOAD_IMAGE_COLOR );
		IplImage* img2 = cvLoadImage( argv[2], CV_LOAD_IMAGE_COLOR );
		
		if( !img1 || !img2 ) {
			return -1;
		}

		cvNamedWindow( "img1", CV_WINDOW_AUTOSIZE );
		cvNamedWindow( "img2", CV_WINDOW_AUTOSIZE );

		cvShowImage( "img1", img1 );
		cvShowImage( "img2", img2 );

		IplImage* gray1 = cvCreateImage( cvGetSize(img1), IPL_DEPTH_8U, 1 );
		IplImage* gray2 = cvCreateImage( cvGetSize(img2), IPL_DEPTH_8U, 1 );

		cvNamedWindow( "gray1", CV_WINDOW_AUTOSIZE );
		cvNamedWindow( "gray2", CV_WINDOW_AUTOSIZE );

		cvCvtColor( img1, gray1, CV_RGB2GRAY );
		cvCvtColor( img2, gray2, CV_RGB2GRAY );

		cvShowImage( "gray1", gray1 );
		cvShowImage( "gray2", gray2 );
		
		// Part A:
		//

		IplImage* dst1 = cvCreateImage( cvGetSize(gray1), IPL_DEPTH_8U, 1 );
		cvNamedWindow( "dst1", CV_WINDOW_AUTOSIZE );
		cvAbsDiff( gray1, gray2, dst1 );
		cvShowImage( "dst1", dst1 );

		// Part B:
		//
		double threshold = argc>3 ? atof(argv[3]) : 100;

		IplImage* binary1 = cvCreateImage( cvGetSize(dst1), IPL_DEPTH_8U, 1 );
		cvNamedWindow( "binary1", CV_WINDOW_AUTOSIZE );
		cvThreshold( dst1, binary1, threshold, 255, CV_THRESH_BINARY );
		cvShowImage( "binary1", binary1 );

		// Part C:
		//
		IplImage* dst2 = cvCreateImage( cvGetSize(dst1), IPL_DEPTH_8U, 1 );
		cvNamedWindow( "dst2", CV_WINDOW_AUTOSIZE );
		cvMorphologyEx(
			dst1,
			dst2,
			NULL,
			NULL,
			CV_MOP_OPEN,
			1
		);
		cvShowImage( "dst2", dst2 );

		IplImage* binary2 = cvCreateImage( cvGetSize(dst2), IPL_DEPTH_8U, 1 );
		cvNamedWindow( "binary2", CV_WINDOW_AUTOSIZE );
		cvThreshold( dst2, binary2, threshold, 255, CV_THRESH_BINARY );
		cvShowImage( "binary2", binary2 );

		// For Exercise 5.6 Binary Image
		// Save The Result
		//
		if ( argc > 4 ) {
			char *save_name = argv[4];
			cvSaveImage( save_name, binary1 );  // save binary1
		}
		if ( argc > 5 ) {
			char *save_name = argv[5];
			cvSaveImage( save_name, binary2 );  // save binary2
		}

		cvWaitKey(0);

		cvReleaseImage( &img1 );
		cvReleaseImage( &img2 );
		cvReleaseImage( &gray1 );
		cvReleaseImage( &gray2 );
		cvReleaseImage( &dst1 );
		cvReleaseImage( &dst2 );
		cvReleaseImage( &binary1 );

		cvDestroyWindow( "img1" );
		cvDestroyWindow( "img2" );
		cvDestroyWindow( "gray1" );
		cvDestroyWindow( "gray2" );
		cvDestroyWindow( "dst1" );
		cvDestroyWindow( "dst2" );
		cvDestroyWindow( "binary1" );
	}

	return 0;
}

