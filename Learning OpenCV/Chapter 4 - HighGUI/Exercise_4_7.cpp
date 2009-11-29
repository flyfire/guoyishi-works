/////////////////////////////////////////////////////////////////
// Date:       2009-10-18
// Author:     Yishi Guo
// Exercise:   4.7
// Page:       108p
// Content:    Perspective transform
// Functions:  cvmGet, cvmSet, cvWarpPerspective
// Website:    http://meiyou.org/
/////////////////////////////////////////////////////////////////

#include <iostream.h>
#include <cv.h >
#include <highgui.h>

// Get the row and col of the matrix
//
void get_row_col( char key, int& row, int& col, bool& is_shift ) {
	// If shift key is not pressed
	switch( key ) {
		case '1': row = 0; col = 0; break;
		case '2': row = 0; col = 1; break;
		case '3': row = 0; col = 2; break;
		case '4': row = 1; col = 0; break;
		case '5': row = 1; col = 1; break;
		case '6': row = 1; col = 2; break;
		case '7': row = 2; col = 0; break;
		case '8': row = 2; col = 1; break;
		case '9': row = 2; col = 2; break;
		default: row = 0; col = 0; break;
	}
	if( '1' <= key && key <= '9' ) {
		is_shift = false;
		return;
	} else {
		is_shift = true;
	}

	// If shift key is pressed
	//
	switch( key ) {
		case '!': row = 0; col = 0; break;
		case '@': row = 0; col = 1; break;
		case '#': row = 0; col = 2; break;
		case '$': row = 1; col = 0; break;
		case '%': row = 1; col = 1; break;
		case '^': row = 1; col = 2; break;
		case '&': row = 2; col = 0; break;
		case '*': row = 2; col = 1; break;
		case '(': row = 2; col = 2; break;
		default: row = 0; col = 0; break;
	}
}

// Output the matrix
//
void cout_mat( CvMat* matrix ) {
	CvSize size = cvGetSize( matrix );
	for ( int i = 0; i < size.width; i++ ) {
		for ( int j = 0; j < size.height; j++ ) {
			cout << cvmGet( matrix, i, j ) << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main( int argc, char** argv ) {
	if ( argc >= 2 ) {

		// Get two images
		//
		IplImage* src = cvLoadImage( argv[1] );
		if ( !src ) {
			return -1;
		}

		IplImage* dst = cvCloneImage( src );
		cvZero( dst );

		// Create mat
		//
		CvMat* warp_matrix = cvCreateMat( 3, 3, CV_32FC1 );
		cvZero( warp_matrix );

		// Show images
		//
		cvNamedWindow( "Exercise 4-7 src", CV_WINDOW_AUTOSIZE );
		cvNamedWindow( "Exercise 4-7 dst", CV_WINDOW_AUTOSIZE );

		cvShowImage( "Exercise 4-7 src", src );
		cvShowImage( "Exercise 4-7 dst", dst );

		while ( 1 ) {
			char key = cvWaitKey(0);
			if ( key == 27 ) break;

			int row = 0, col = 0;
			bool is_shift = false;

			// Get row and col
			get_row_col( key, row, col, is_shift );
			
			// Get the value at row&col
			double value = cvmGet( warp_matrix, row, col );

			if ( is_shift ) {
				--value;
			} else {
				++value;
			}
			cvmSet( warp_matrix, row, col, value );

			// For debug
			//
			cout << key << endl;
			cout_mat( warp_matrix );  // Test for the warp matrix

			// Process
			//
			cvWarpPerspective( src, dst, warp_matrix );
			cvShowImage( "Exercise 4-7 dst" , dst );
		}

		cvReleaseMat( &warp_matrix );
		cvReleaseImage( &src );
		cvReleaseImage( &dst );

		cvDestroyWindow( "Exercise 4-7 src" );
		cvDestroyWindow( "Exercise 4-7 dst" );

		return 0;
	}
	return -2;
}