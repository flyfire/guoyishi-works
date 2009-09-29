////////////////////////////////////
// Date:      2009-09-26
// Author:    Yishi Guo
// Chapter:   5
// Exercise:  5.2
// Content:   Smooth one pixel
////////////////////////////////////
#include "cv.h"
#include "highgui.h"

int main( int argc, char** argv ) {
	// Create images
	// 
	IplImage* src = cvCreateImage( cvSize(100, 100), IPL_DEPTH_8U, 1 );
	int color = 255;
	((uchar*)(src->imageData + src->widthStep*50))[50] = color;

	IplImage* dst1 = cvCreateImage( cvGetSize(src), src->depth, src->nChannels );
	IplImage* dst2 = cvCreateImage( cvGetSize(src), src->depth, src->nChannels );

	// Do something on the images
	//
	cvSmooth( src, dst1, CV_GAUSSIAN, 5, 5 );
	cvSmooth( dst1, dst1, CV_GAUSSIAN, 5, 5 );
	cvSmooth( src, dst2, CV_GAUSSIAN, 9, 9 );

	// Create windows
	//

	cvNamedWindow( "src", CV_WINDOW_AUTOSIZE );
	cvNamedWindow( "dst1", CV_WINDOW_AUTOSIZE );
	cvNamedWindow( "dst2", CV_WINDOW_AUTOSIZE );

	// Show images
	//

	cvShowImage( "src", src );
	cvShowImage( "dst1", dst1 );
	cvShowImage( "dst2", dst2 );
	
	cvWaitKey();

	// Clear up resources
	//
	cvReleaseImage( &src );
	cvReleaseImage( &dst1 );
	cvReleaseImage( &dst2 );

	cvDestroyWindow( "src" );
	cvDestroyWindow( "dst1" );
	cvDestroyWindow( "dst2" );

	return 0;
}