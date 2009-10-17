/////////////////////////////////////////////////////////////////
// Date:      2009-10-16
// Author:    Yishi Guo
// Exercise:  3.5
// Page:      88
// Content:   Practice using region of interest(ROI).
/////////////////////////////////////////////////////////////////
#include <cv.h>
#include <highgui.h>

int main( int argc, char** argv ) {
	IplImage* img = cvCreateImage(
		cvSize(210, 210),
		IPL_DEPTH_8U,
		1 
	);
	cvSetZero( img );

	// Processing
	//
	for ( int value = 0, x = 0;
	      value <= 200;
		  value += 20, x += 10 ) {
		CvRect rect = cvRect( x, x, 210-2*x, 210-2*x );  // ROI Rectangle 
		                                                 // cvRect( int x, int y, int width, int height );
		cvSetImageROI( img, rect );  // Set Image ROI
		cvSet( img, cvScalarAll(value) );  // Set the ROI Value
		cvResetImageROI( img );  // Release Image ROI
	}

	cvNamedWindow( "Exercise 3-5", CV_WINDOW_AUTOSIZE );
	cvShowImage( "Exercise 3-5", img );

	cvWaitKey(0);

	cvReleaseImage( &img );
	cvDestroyWindow( "Exercise 3-5" );

	return 0;
}
