///////////////////////////////////////////////////////////////////
// Date:      2009-10-16
// Author:    Yishi Guo
// Exercise:  3.4
// Page:      88
// Content:   cvZero, cvPtr2D, cvCreateImage
///////////////////////////////////////////////////////////////////
#include <cv.h>
#include <highgui.h>

int main( int argc, char** argv ) {
	IplImage* img = cvCreateImage(
		cvSize(100, 100),
		IPL_DEPTH_32F,
		3
	);
	cvZero(img);

	for ( int i = 5; i < 20; ++i ) {  // rows
		for ( int j = 20; j < 40; ++j ) {  // cols
			float* ptr = (float*)cvPtr2D( img, i, j );  // Get the point value
			ptr[1] = 255;  // Set the value of the point
		}
	}

	cvNamedWindow( "Exercise 3-4", CV_WINDOW_AUTOSIZE );
	cvShowImage( "Exercise 3-4", img );

	cvWaitKey(0);

	cvReleaseImage( &img );
	cvDestroyWindow( "Exercise 3-4" );

	return 0;
}