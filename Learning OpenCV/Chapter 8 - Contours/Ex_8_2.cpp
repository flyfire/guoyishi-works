/////////////////////////////////////////////////////////////////////////
// Date: 2009-10-12
// Coder: Yishi Guo
// Copy From: Example 8-2
// Content: Example 8-2
//          Finding coutours based on a trackbar's location;
//          the contours are updated whenever the trackbar is moved
/////////////////////////////////////////////////////////////////////////
#include <cv.h>
#include <highgui.h>

IplImage*     g_image   = NULL;
IplImage*     g_gray    = NULL;
int           g_thresh  = NULL;
CvMemStorage* g_storage = NULL;

void on_trackbar( int ) {
	if ( g_storage == NULL ) {
		g_gray = cvCreateImage( cvGetSize( g_image ), 8, 1 );
		g_storage = cvCreateMemStorage(0);
	} else {
		cvClearMemStorage( g_storage );
	}
	CvSeq* contours = 0;
	cvCvtColor( g_image, g_gray, CV_BGR2GRAY );
	cvThreshold( g_gray, g_gray, g_thresh, 255, CV_THRESH_BINARY );
	cvFindContours( g_gray, g_storage, &contours );
	cvZero( g_gray );
	if ( contours ) {
		cvDrawContours(
			g_gray,
			contours,
			cvScalarAll(255),
			cvScalar(150, 45, 100),
			100
		);
	}
	cvShowImage( "Contours", g_gray );
}

int main( int argc, char** argv ) {
	if ( argc != 2 || !(g_image = cvLoadImage( argv[1] ) ) ) {
		return -1;
	}

	cvNamedWindow( "Contours", 1 );
	cvCreateTrackbar(
		"Threshold",
		"Contours",
		&g_thresh,
		255,
		on_trackbar
	);
	on_trackbar(0);
	cvWaitKey(0);

	return 0;
}