///////////////////////////////////////////
// Date: 2009-10-15
// Author: Yishi Guo
// Exercise: 2.5
// Page: 30
// Content: Trackbar, cvResize
///////////////////////////////////////////
#include <cv.h>
#include <highgui.h>
#define COUNT 8

int g_slider_position_in = 0;
int g_slider_position_out = 0;
IplImage* g_src = NULL;
IplImage* g_dst = NULL;

void ResizeTimes( IplImage* src, IplImage* dst, int times, bool zoom_in ) {
	int width = src->width;
	int height = src->height;

	if ( times > 0 ) {
		if ( zoom_in ) {
			width *= times;
			height *= times;
		} else {
			if ( width % times ) {
				width += width % times;
			}
		
			if ( height % times ) {
				height += height % times;
			}

			width /= times;
			height /= times;
		}
	}

	// IplImage* l_dst = cvCreateImage( cvSize(width, height), src->depth, src->nChannels );
	dst = cvCreateImage( cvSize(width, height), src->depth, src->nChannels );

	// cvResize( src, l_dst, CV_INTER_LINEAR );
	cvResize( src, dst, CV_INTER_LINEAR );

	// cvShowImage( "Exercise 5 - dst", l_dst );
	cvShowImage( "Exercise 5 - dst", dst );

	// cvReleaseImage( &l_dst );
	cvReleaseImage( &dst );
}

void ImageResize( IplImage* src, IplImage* dst, int pos, bool zoom_in ) {
	for ( int i = 0; i <= pos; i++ ) {
		ResizeTimes( src, dst, pos, zoom_in );
	}
}

void onTrackbarSlide_in( int pos ) {
	if ( pos != 0 ) {
		cvSetTrackbarPos( "Zoom out", "Exercise 5 - src", 0 );
	}
	ImageResize( g_src, g_dst, pos, true );
}

void onTrackbarSlide_out( int pos ) {
	if ( pos != 0 ) {
		cvSetTrackbarPos( "Zoom in", "Exercise 5 - src", 0 );
	}
	ImageResize( g_src, g_dst, pos, false );
}

int main( int argc, char** argv ) {
	if ( argc >= 2 ) {

		g_src = cvLoadImage( argv[1] );
		cvNamedWindow( "Exercise 5 - src", CV_WINDOW_AUTOSIZE );
		cvShowImage( "Exercise 5 - src", g_src );
		cvNamedWindow( "Exercise 5 - dst", CV_WINDOW_AUTOSIZE );
		cvShowImage( "Exercise 5 - dst", g_src );

		int count1 = (argc >= 3) ? atoi(argv[2]) : COUNT;
		int count2 = (argc >= 4) ? atoi(argv[3]) : COUNT;

		if ( count1 > 0 && count2 > 0) {
			cvCreateTrackbar(
				"Zoom in",
				"Exercise 5 - src",
				&g_slider_position_in,
				count1,
				onTrackbarSlide_in
			);

			cvCreateTrackbar(
				"Zoom out",
				"Exercise 5 - src",
				&g_slider_position_out,
				count2,
				onTrackbarSlide_out
			);
		}

		while ( 1 ) {
			// cvShowImage( "Exercise 5", g_dst );
			if (cvWaitKey(0) == 27 ) {
				break;
			}
		}

		cvReleaseImage( &g_src );
		cvReleaseImage( &g_dst );
		cvDestroyWindow( "Exercise 5 - src" );
		cvDestroyWindow( "Exercise 5 - dst" );

		return 0;
	}
	return -1;
}
