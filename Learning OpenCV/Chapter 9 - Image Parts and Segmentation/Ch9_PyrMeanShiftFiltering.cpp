///////////////////////////////////////////
// Date:    2010-01-20
// Author:  Yishi Guo
// About:   cvPyrMeanShiftFiltering
///////////////////////////////////////////
#include "cv.h"
#include "highgui.h"
#include <stdio.h>

double sp = 10;
double sr = 40;
int max_level = 1;

int main( int argc, char** argv ) {
	IplImage *img, *dst;
	char* filename = argc >= 2 ? argv[1] : (char*)"fruits.jpg";

	if ( (img = cvLoadImage( filename, 1 ) ) == 0 ) {
		printf( "Could not load the image %s", filename );
		return 0;
	}

	dst = cvCloneImage( img );

	cvNamedWindow( "image", CV_WINDOW_AUTOSIZE );
	cvNamedWindow( "cvPyrMeanShiftFiltering", CV_WINDOW_AUTOSIZE );

	cvShowImage( "image", img );  // show the original image

	for ( ; ; ) {
		double t = (double)cvGetTickCount();  // count the process time

		cvPyrMeanShiftFiltering( img, dst, sp, sr, max_level );  // do it

		t = (double)cvGetTickCount() - t;
		printf( "exec time = %gms\n", t/(cvGetTickFrequency()*1000.) );

		cvShowImage( "cvPyrMeanShiftFiltering", dst );

		char ch = cvWaitKey( 0 );

		if ( ch == 27 ) {
			break;
		} else if ( ch == '-' || ch == '_' ) {  // change sp value
			sp -= 1.0;
			printf( "sp = %g\n", sp );
		} else if ( ch == '+' || ch == '=' ) {
			sp += 1.0;
			printf( "sp = %g\n", sp );
		} else if ( ch == '[' || ch == '{' ) {  // change sr value
			sr -= 1.0;
			printf( "sr = %g\n", sr );
		} else if ( ch == ']' || ch == '}' ) {
			sr += 1.0;
			printf( "sr = %g\n", sr );
		}
	}

	cvReleaseImage( &img );
	cvReleaseImage( &dst );
	
	cvDestroyWindow( "image" );
	cvDestroyWindow( "cvPyrMeanShiftFiltering" );

	return 1;
}