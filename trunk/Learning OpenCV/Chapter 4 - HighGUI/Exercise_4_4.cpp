///////////////////////////////////////////////
// Date:      2009-10-17
// Author:    Yishi Guo
// Exercise:  4.4
// Page:      107
// Content:   Capture, Frame, Trackbar
///////////////////////////////////////////////
#include <cv.h>
#include <highgui.h>
#include <iostream.h>

CvCapture* g_capture = NULL;
IplImage* g_frame = NULL;

int g_position_value = 0;
int g_pause_value = 0;

int g_now_frame = 0;
int g_frame_count = 1;

bool g_pause = false;

// "Position" trackbar position
//
void position_callback( int pos ) {
		
	g_now_frame = pos * g_frame_count / 10;
	cvSetCaptureProperty(
		g_capture,
		CV_CAP_PROP_POS_FRAMES,
		g_now_frame
	);

	if ( g_pause ) {
		g_frame = cvQueryFrame( g_capture );
		cvShowImage( "Exercise 4-4", g_frame );
	}
}

// "Pause" trackbar callback
//
void pause_callback( int pos ) {
	if ( pos ) {
		g_pause = true;
	} else {
		g_pause = false;
	}
}

// Set the "Position" trackbar position
//
void set_position( CvCapture* capture ) {
	++g_now_frame;
	int pos = g_now_frame * 10 / g_frame_count;

	// For debug
	// cout << "Pos: " << pos << " Now: " << g_now_frame
	// 	 << " Count: " << g_frame_count << endl;

	cvSetTrackbarPos(
		"Position",
		"Exercise 4-4",
		pos
	);
}

int main( int argc, char** argv ) {
	if ( argc >= 2 ) {
		g_capture = cvCreateFileCapture( argv[1] );  // Get capture
		if ( !g_capture ) {
			return -1;
		}

		g_frame_count = (int)cvGetCaptureProperty(  // Get frame count
			g_capture,
			CV_CAP_PROP_FRAME_COUNT
		);

		cvNamedWindow( "Exercise 4-4", CV_WINDOW_AUTOSIZE );

		cvCreateTrackbar(  // Create "Position" trackbar
			"Position",
			"Exercise 4-4",
			&g_position_value,
			10,
			position_callback
		);

		cvCreateTrackbar(  // Create "Pause" trackbar
			"Pause",
			"Exercise 4-4",
			&g_pause_value,
			1,
			pause_callback
		);

		char down_key;
		while ( 1 ) {
			if ( !g_pause ) {  // If not pause
				g_frame = cvQueryFrame( g_capture );
				set_position( g_capture );
			}
			if ( !g_frame ) break;
			cvShowImage( "Exercise 4-4", g_frame );

			down_key = cvWaitKey(33);
			if ( down_key == 27 ) {
				break;
			} else if ( down_key == ' ' ) {
				int pos = 0;
				if ( g_pause ) {
					g_pause = false;
					pos = 0;
				} else {
					g_pause = true;
					pos = 1;
				}

				cvSetTrackbarPos(
					"Pause",
					"Exercise 4-4",
					pos
				);
			}
		}

		cvReleaseImage( &g_frame );
		cvReleaseCapture( &g_capture );
		cvDestroyWindow( "Exercise 4-4" );

		return 0;
	}
	return -1;
}


