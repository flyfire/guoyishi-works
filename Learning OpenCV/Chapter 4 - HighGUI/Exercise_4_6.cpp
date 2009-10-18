///////////////////////////////////////////////
// Date:      2009-10-18
// Author:    Yishi Guo
// Exercise   4.6
// Page:      108
// Content:   Label a image
///////////////////////////////////////////////
#include <cv.h>
#include <highgui.h>
#include <string>
#include <iostream.h>
using namespace std;

bool g_typing = false;
string g_str;
CvPoint g_point;

void draw_string( IplImage* img, CvPoint point, string str ) {
	CvFont font;
	const char* text = str.data();
	cvInitFont(
		&font,
		CV_FONT_HERSHEY_SIMPLEX,
		0.5,
		0.5
	);
	cvPutText(
		img,
		text,
		point,
		&font,
		cvScalarAll(255)
	);

	// For Debug
	// cout << "Point: (" << point.x << "," << point.y << ")" << endl;
}

void on_mouse( int event, int x, int y, int flags, void* param ) {
	IplImage* img = (IplImage*)param;
	switch( event ) {
		case CV_EVENT_LBUTTONDOWN: {
			if ( !g_typing ) {
				g_typing = true;
			}
			g_point = cvPoint( x, y );
		}
		break;
	}
}

void clear_string( string& str ) {
	int size = str.size();
	str.erase( 0, size );
}

int main( int argc, char** argv ) {
	IplImage* src;
	if ( argc >= 2 ) {
		src = cvLoadImage( argv[1] );
	} else {
		src = cvCreateImage( cvSize(320, 240), IPL_DEPTH_8U, 1 );
		cvZero( src );
	}

	IplImage* img = cvCloneImage( src );
	IplImage* temp = cvCloneImage( src );

	cvNamedWindow( "Exercise 4-6", CV_WINDOW_AUTOSIZE );
	cvShowImage( "Exercise 4-6", img );

	cvSetMouseCallback(
		"Exercise 4-6",
		on_mouse,
		(void*)img
	);

	while( 1 ) {
		char key = cvWaitKey(0);
		if ( key == 27 ) {
			break;
		}

		if ( g_typing ) {
			if ( key == 13 ) { // Carriage Return
				cvCopyImage( temp, img );
				g_typing = false;
				clear_string( g_str );
			} else if ( key == 8 ) {  // Backspace
				if ( !g_str.empty() ){
					g_str.resize(g_str.size()-1);
				}
				cvCopyImage( img, temp );
				draw_string( temp, g_point, g_str );
			} else {  // Text char
				g_str += key;
				cvCopyImage( img, temp );
				draw_string( temp, g_point, g_str );
			}
			cvShowImage( "Exercise 4-6", temp );
		} else {
			// cvCopyImage( img, temp );
			cvShowImage( "Exercise 4-6", img );
		}
	}

	cvReleaseImage( &img );
	cvDestroyWindow( "Exercise 4-6" );

	return 0;
}