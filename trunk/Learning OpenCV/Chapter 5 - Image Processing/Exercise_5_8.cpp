//////////////////////////////////////////////////
// Date:     2009-10-29
// Author:   Yishi Guo
// Exercise: 5.8
// Chapter:  5 Image Processing
// Page:     142p
// Content:  cvRandInt, cvRectangle
//////////////////////////////////////////////////
#include "cv.h"
#include "highgui.h"

int main( int argc, char** argv ) {
	int width = 640, height = 480;
	IplImage* img = cvCreateImage( cvSize(width, height), IPL_DEPTH_8U, 3 );
	cvZero( img );  // Set the image to 0

	CvRNG rng = cvRNG( -1 );
	// cvRandInit( &rng, 0, 1, 0xffffff, CV_RAND_UNI );

	// Set value
	//
	int value = 100;
	if( argc > 1 ) {
		value = atoi( argv[1] );
	}

	// Set Difference
	//
	int diff = 2;
	if ( argc > 2 ) {
		diff = atoi( argv[2] );
	}

	// Set point count
	//
	int pointCount = 10;
	if( argc > 3 ) {
		pointCount = atoi( argv[3] );
	}

	int i;
	for( i = 0; i < pointCount; ++i ) {
		CvPoint pt1, pt2;
		pt1.x = cvRandInt(&rng) % (img->width-2);
		pt1.y = cvRandInt(&rng) % (img->height-2);

		pt2.x = pt1.x + 2;
		pt2.y = pt1.y + 2;

		// Draw "rectangle point"
		//
		CvScalar color = cvScalarAll( value + cvRandInt(&rng)%diff );
		cvRectangle( img, pt1, pt2, color, CV_FILLED );
	}

	cvNamedWindow( "Exercise 5-8", CV_WINDOW_AUTOSIZE );
	cvShowImage( "Exercise 5-8", img );

	if ( cvWaitKey(0) == 's' ) {
		char* save_name = "Ex_5_8_save_image.jpg";
		if ( argc > 4 ) {
			save_name = argv[4];
		}
		cvSaveImage( save_name, img );
	}

	cvReleaseImage( &img );
	cvDestroyWindow( "Exercise 5-8" );

	return 0;
}