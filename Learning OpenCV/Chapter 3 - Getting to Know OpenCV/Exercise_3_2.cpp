/////////////////////////////////////////////////
// Date:      2009-10-15
// Author:    Yishi Guo
// Exercise:  3.2
// Page:      88
// Content:   cvCreateMat, cvSet, cvCircle
/////////////////////////////////////////////////
#include <cv.h>
#include <highgui.h>
#define ROWS_SIZE 100
#define COLS_SIZE 100

int main( int argc, char** argv ) {
	CvMat* mat = cvCreateMat( ROWS_SIZE, COLS_SIZE, CV_32FC3 );
	cvSet( mat, cvScalarAll(0), 0 );  // Set all the values to 0.

	// Part-A:
	// Draw a circle in the matrix using cvCircle
	//
	cvCircle(
		mat,  // image
		cvPoint( 50, 50 ),  // center point
		30,  // radius
		CV_RGB(255, 0, 0),  // color
		1,  // thickness
		8,  // line type
		0
	);

	// Part-B:
	// Display this image
	//
	cvNamedWindow( "Exercise 3-2", CV_WINDOW_AUTOSIZE );
	cvShowImage( "Exercise 3-2", mat );

	cvWaitKey(0);

	cvReleaseMat( &mat );
	cvDestroyWindow( "Exercise 3-2" );

	return 0;
}


