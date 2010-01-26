/////////////////////////
// Date:       2010-01-24
// Coder:      Yishi Guo
// About:      Test for draw arrow
// References: http://robots.stanford.edu/cs223b05/notes/CS%20223-B%20T1%20stavens_opencv_optical_flow.pdf
/////////////////////////
#include "cv.h"
#include "highgui.h"

static const double pi = 3.14159265358979323846;

void draw_cross( IplImage* img, CvPoint p0, CvPoint p1, int length = 10 ) {
	double a, b, k;
	k = ( p1.y - p0.y ) / ( p1.x - p0.x );
	b = sqrt( length * length / ( k * k + 1 ) );
	a = b * k;

	CvPoint p_a = cvPoint( p1.x + (int)a, p1.y - (int)b );
	CvPoint p_b = cvPoint( p1.x - (int)a, p1.y + (int)b );

	cvLine( img, p1, p_a, CV_RGB( 0, 255, 0 ), 2, CV_AA );
	cvLine( img, p1, p_b, CV_RGB( 0, 0, 255 ), 2, CV_AA );

}

void draw_arrow( IplImage* img, CvPoint p0, CvPoint p1, int length = 10 ) {
	///////////
	// Copy From: http://robots.stanford.edu/cs223b05/notes/CS%20223-B%20T1%20stavens_opencv_optical_flow.pdf
	///////////
	double angle;
	angle = atan2( (double)p0.y - p1.y, (double)p0.x - p1.x );

	cvLine( img, p0, p1, CV_RGB( 255, 0, 0 ), 2, CV_AA, 0 );

	p0.x = (int) ( p1.x + 9 * cos( angle + pi / 4 ) );
	p0.y = (int) ( p1.y + 9 * sin( angle + pi / 4 ) );
	cvLine( img, p0, p1, CV_RGB( 0, 255, 0 ), 2, CV_AA, 0 );

	p0.x = (int) ( p1.x + 9 * cos( angle - pi / 4 ) );
	p0.y = (int) ( p1.y + 9 * sin( angle - pi / 4 ) );
	cvLine( img, p0, p1, CV_RGB( 0, 0, 255 ), 2, CV_AA, 0 );
}

int main( int argc, char** argv ) {
	CvPoint p0 = cvPoint( 10, 50 );
	CvPoint p1 = cvPoint( 30, 50 );

	if ( argc >= 2 ) {
		p0 = cvPoint( atoi( argv[1] ), atoi( argv[1] ) );
	}
	if ( argc >= 3 ) {
		p1 = cvPoint( atoi( argv[2] ), atoi( argv[2] ) );
	}

	IplImage* img = cvCreateImage( cvSize( 400, 400 ), IPL_DEPTH_8U, 3 );
	cvZero( img );

	// cvLine( img, p0, p1, CV_RGB( 255, 0, 0 ), 2, CV_AA );

	// draw_cross( img, p0, p1 );

	draw_arrow( img, p0, p1, 30 );

	cvNamedWindow( "Draw Arrow", CV_WINDOW_AUTOSIZE );

	cvShowImage( "Draw Arrow", img );

	cvWaitKey( 0 );

	cvDestroyWindow( "Draw Arrow" );
	cvReleaseImage( &img );

	return 0;
}
