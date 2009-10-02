/////////////////////////////////////////////
// Date:       2009-09-30
// Author:     Yishi Guo
// Chapter:    5
// Page:       129
// Content:    Resize | Image Processing
/////////////////////////////////////////////
#include <iostream>
#include "cv.h"
#include "highgui.h"

using namespace std;

int main( int argc, char** argv ) {
	if ( argc >= 2 ) {
		// Get images
		//
		IplImage* src = cvLoadImage( argv[1] );
		IplImage* dst1 = cvCreateImage(
			cvSize( atoi(argv[2]), atoi(argv[3]) ),
			src->depth,
			src->nChannels
			);
		IplImage* dst2 = cvCloneImage( dst1 );
		IplImage* dst3 = cvCloneImage( dst1 );
		IplImage* dst4 = cvCloneImage( dst1 );

		// Create Images
		//
		cvNamedWindow( "src", CV_WINDOW_AUTOSIZE );
		cvNamedWindow( "CV_INTER_LINEAR", CV_WINDOW_AUTOSIZE );
		cvNamedWindow( "CV_INTER_NN", CV_WINDOW_AUTOSIZE );
		cvNamedWindow( "CV_INTER_AREA", CV_WINDOW_AUTOSIZE );
		cvNamedWindow( "CV_INTER_CUBIC", CV_WINDOW_AUTOSIZE );

		// Resize the Images
		//
		cvResize( src, dst1, CV_INTER_LINEAR );
		cvResize( src, dst2, CV_INTER_NN );
		cvResize( src, dst3, CV_INTER_AREA );
		cvResize( src, dst4, CV_INTER_CUBIC );

		// Show Images
		//
		cvShowImage( "src", src );
		cvShowImage( "CV_INTER_LINEAR", dst1 );
		cvShowImage( "CV_INTER_NN", dst2 );
		cvShowImage( "CV_INTER_AREA", dst3 );
		cvShowImage( "CV_INTER_CUBIC", dst4 );

		// Wait a key
		// 
		cvWaitKey();

		// Save the image(CV_INTER_LINEAR)
		// 
		cvSaveImage( argv[4], dst1 );

		// Release Resources
		cvReleaseImage( &src );
		cvReleaseImage( &dst1 );
		cvReleaseImage( &dst2 );
		cvReleaseImage( &dst3 );
		cvReleaseImage( &dst4 );

		cvDestroyWindow( "src" );
		cvDestroyWindow( "CV_INTER_LINEAR" );
		cvDestroyWindow( "CV_INTER_NN" );
		cvDestroyWindow( "CV_INTER_AREA" );
		cvDestroyWindow( "CV_INTER_CUBIC" );
	} else {
		cout << "Resize_image Help:" << endl;
		cout << "Resize_image file_name new_width new_height new_file_name" << endl;
	}
	return 0;
}