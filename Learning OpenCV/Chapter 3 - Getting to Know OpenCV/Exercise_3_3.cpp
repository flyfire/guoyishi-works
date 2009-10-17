/////////////////////////////////////////
// Date:      2009-10-15
// Author:    Yishi Guo
// Exercise:  3.3
// Page:      88
// Content:   cvPtr2D
//////////////////////////////////////////////
#include <cv.h>
#include <highgui.h>
#include <iostream.h>

int main( int argc, char** argv ) {
	CvMat* mat = cvCreateMat( 100, 100, CV_32FC3 );
	cvSet( mat, cvScalarAll(0), 0 );

	for ( int rows = 5; rows <= 20; ++rows ) {
		for ( int cols = 20; cols <= 40; ++cols ) {
			float* ptr = (float*)cvPtr2D( mat, rows, cols );
			// cout << ptr[0] << ", " << ptr[1] << ", " << ptr[2] << endl;
			ptr[1] = 255;
		}
	}

	cvNamedWindow( "Exercise 3-3", CV_WINDOW_AUTOSIZE );
	cvShowImage( "Exercise 3-3", mat );

	cvWaitKey(0);

	cvReleaseMat( &mat );
	cvDestroyWindow( "Exercise 3-3" );

	return 0;
}
