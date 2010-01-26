//////////////////////////////////////////////////
// Date:   2009-10-30
// Author: Yishi Guo
// Where:  HOME!
// Name:   Space & Stars
// For:    Fun
//////////////////////////////////////////////////
#include "cv.h"
#include "highgui.h"
#include <iostream.h>
#include <math.h>

int width = 640, height = 480;
int center_rect_width = 1, center_rect_height = 1;

int center_rect_x;
int center_rect_y;
uchar max_move_x = 10, max_move_y = 10;
uchar increment_x = 1, increment_y = 1;

bool is_debug = false;

int size = 300;

CvRNG rng = cvRNG( -1 );

typedef struct PointMove {
	int x;
	int y;
	int move_x;
	int move_y;
} PointMove;

void rand_PointMove( PointMove& pm ) {
	pm.x = cvRandInt(&rng) % center_rect_width + center_rect_x;
	pm.y = cvRandInt(&rng) % center_rect_height + center_rect_y;

	do {
		pm.move_x = (cvRandInt(&rng) % max_move_x) * (cvRandInt(&rng)%2==1 ? -1 : 1);
		pm.move_y = (cvRandInt(&rng) % max_move_y) * (cvRandInt(&rng)%2==1 ? -1 : 1);
	} while ( !pm.move_x && !pm.move_y );
}

void draw_point( IplImage* img, PointMove& pm ) {
	pm.x = pm.x+pm.move_x;
	pm.y = pm.y+pm.move_y;

	// For debug
	if( is_debug ) {
		cout << "(" << pm.x << "," << pm.y << ")" << endl;
		cout << "width: " << img->width << " height: " << img->height << endl;
	}
	

	if ( pm.x >= img->width || pm.y >= img->height ||
		pm.x < 0 || pm.y < 0) {

		rand_PointMove( pm );

		// For debug
		if( is_debug ) {
			cout << "move_x: " << pm.move_x << " move_y: " << pm.move_y << endl;
		}
	}

	CvScalar color = cvScalarAll( 255 );
	CvPoint pt1 = cvPoint(pm.x, pm.y);
	CvPoint pt2 = cvPoint(pm.x+2, pm.y+2);
	cvRectangle( img, pt1, pt2, color, CV_FILLED );
}


void get_space_image( IplImage* src, IplImage* dst, PointMove pms[] ) {
	cvCopy( src, dst );

	int i;
	for( i = 0; i < size; ++i ) {
		draw_point( dst, pms[i] );
	}
}


int main( int argc, char** argv ) {
	const char* debug_opt = "--debug=";
	int debug_opt_len = strlen( debug_opt );

	const char* size_opt = "--size=";
	int size_opt_len = strlen( size_opt );

	const char* width_opt = "--width=";
	int width_opt_len = strlen( width_opt );

	const char* height_opt = "--height=";
	int height_opt_len = strlen( height_opt );

	int i;
	for( i = 0; i < argc; ++i ) {
		if ( strncmp( size_opt, argv[i], size_opt_len ) == 0 ) {
			size = atoi( argv[i] + size_opt_len );
		} else if ( strncmp( width_opt, argv[i], width_opt_len ) == 0 ) {
			width = atoi( argv[i] + width_opt_len );
		} else if ( strncmp( height_opt, argv[i], height_opt_len ) == 0 ) {
			height = atoi( argv[i] + height_opt_len );
		} else if ( strncmp( debug_opt, argv[i], debug_opt_len ) == 0 ) {
			if ( strcmp( argv[i] + debug_opt_len, "true" ) == 0 ) {
				is_debug = true;
			}
		}
	}

	center_rect_x = (width - center_rect_width) / 2;
	center_rect_y = (height - center_rect_height) / 2;

	IplImage* src = cvCreateImage( cvSize(width, height), IPL_DEPTH_8U, 3 );
	cvZero( src );

	cvNamedWindow( "Space", CV_WINDOW_AUTOSIZE );

	PointMove *pms = new PointMove[size];

	for( i = 0; i < size; ++i ) {
		rand_PointMove( pms[i] );
	}

	IplImage* space = cvCloneImage( src );
	
	int count = 0;
	while( 1 ) {
		int key = cvWaitKey(10);
		if ( key == 27 ) {
			break;
		} else if ( key == 's' ) {
			const char* save_name = "Space.jpg";
			cvSaveImage( save_name, space );
		}

		get_space_image( src, space, pms );
		cvShowImage( "Space", space );
	}

	cvDestroyWindow( "Space" );

	cvReleaseImage( &src );
	cvReleaseImage( &space );

	return 0;
}