//////////////////////////////////////
// Date: 2009-10-25
// Author: Yishi Guo
// Where: HOME!
// About: Just for myself use
//////////////////////////////////////
#include "cv.h"
#include "highgui.h"
#include <string>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <strstream>
using namespace std;

IplImage **g_images;
IplImage **g_show_images;
IplImage **g_canny_images;

string *g_image_names;

int g_threshold_low = 0;
int g_threshold_high = 10;

int g_low_count = 200;
int g_high_count = 200;

int g_image_count = 0;
int g_image_now_index = 0;

void canny_image( IplImage* img, IplImage* dst, int low, int high ) {
	IplImage* gray_img = cvCreateImage( cvGetSize(img), IPL_DEPTH_8U, 1 );
	IplImage* gray_dst = cvCreateImage( cvGetSize(img), IPL_DEPTH_8U, 1 );

	cvCvtColor( img, gray_img, CV_RGB2GRAY );

	cvCanny( gray_img, gray_dst, g_threshold_low, g_threshold_high );

	cvCvtColor( gray_dst, dst, CV_GRAY2RGB );

	cvReleaseImage( &gray_img );
	cvReleaseImage( &gray_dst );
}

void merge_image( IplImage* src, IplImage* canny, IplImage* dst ) {
	int width = src->width, height = src->height;

	cvSetImageROI( dst, cvRect(0, 0, width, height) );
	cvCopy( src, dst );
	cvResetImageROI( dst );

	cvSetImageROI( dst, cvRect(width, 0, width, height) );
	cvCopy( canny, dst );
	cvResetImageROI( dst );
}

void refresh_image() {
	canny_image( g_images[g_image_now_index], g_canny_images[g_image_now_index], g_threshold_low, g_threshold_high );

	// For Debug
	// cout << "Refresh << Canny << OK!" << endl;

	merge_image( g_images[g_image_now_index], g_canny_images[g_image_now_index], g_show_images[g_image_now_index] );

	// For Debug
	// cout << "Refresh << Merge << OK!" << endl;
}

void threshold_low_callback( int pos ) {
	if ( pos > g_threshold_high ) {
		cvSetTrackbarPos( "Low", "Best Threshold", g_threshold_high-1 );
		g_threshold_low = g_threshold_high-1;
	}
	refresh_image();
}

void threshold_high_callback( int pos ) {
	if( g_threshold_low > pos ) {
		cvSetTrackbarPos( "High", "Best Threshold", g_threshold_low+1 );
		g_threshold_high = g_threshold_low+1;
	}
	refresh_image();
}

void switch_image_index( int &index, int count ) {
	index = (index+1) % count;
}

string itos( int n ) {
	strstream ss;
	string s;
	ss << n;
	ss >> s;
	return s;
}


void mouse_callback( int event, int x, int y, int flags, void* param ) {
	switch( event ) {
		case CV_EVENT_LBUTTONDOWN: {
			switch_image_index(g_image_now_index, g_image_count);
			refresh_image();
		}
		break;
		case CV_EVENT_RBUTTONDOWN: {
			string filename = "";
			filename += itos(g_threshold_low) + "_";
			filename += itos(g_threshold_high) + "_";
			filename += g_image_names[g_image_now_index].c_str();
			cvSaveImage( filename.c_str(), g_show_images[g_image_now_index] );
		}
		break;

	}
}

bool cmp_suffix( const char* argv, const char** image_suffix, int length, int size ) {
	int len = strlen( argv );
	const char* last_four_chars = argv + (len-length);
	for ( int j = 0; j < size; ++j ) {
		if ( strncmp( last_four_chars, image_suffix[j], length ) == 0 ) {
			return true;
		}
	}
	return false;
}

int main( int argc, char** argv ) {
	if( argc <= 1 ) {
		return -1;
	} else {
		const char* low_count_opt = "--low=";
		int low_count_opt_len = (int)strlen(low_count_opt);
		const char* high_count_opt = "--high=";
		int high_count_opt_len = (int)strlen(high_count_opt);
		const char* image_suffix[2] = { ".jpg", ".png" };


		int i = 0;
		g_image_count = 0;
		for ( i = 0; i < argc; ++i ) {
			if ( strncmp( argv[i], low_count_opt, low_count_opt_len ) == 0 ) {
				g_low_count = atoi( argv[i] + low_count_opt_len );
			} else if ( strncmp( argv[i], high_count_opt, high_count_opt_len ) == 0 ) {
				g_high_count = atoi( argv[i] + high_count_opt_len );
			} else if ( cmp_suffix( argv[i], image_suffix, 4, 2 ) ) {
				++g_image_count;
			}
		}

		// For Debug
		// cout << g_low_count << " " << g_high_count << endl;

		cvNamedWindow( "Best Threshold", CV_WINDOW_AUTOSIZE );
		g_images = new IplImage*[g_image_count];
		g_canny_images = new IplImage*[g_image_count];
		g_show_images = new IplImage*[g_image_count];

		g_image_names = new string[g_image_count];

		// Create Threshold Trackbars
		//
		cvCreateTrackbar(
			"Low",
			"Best Threshold",
			&g_threshold_low,
			g_low_count,
			threshold_low_callback
		);

		cvCreateTrackbar(
			"High",
			"Best Threshold",
			&g_threshold_high,
			g_high_count,
			threshold_high_callback
		);

		// Set Mouse Callback
		//
		cvSetMouseCallback(
			"Best Threshold",
			mouse_callback,
			(void*)g_show_images[g_image_now_index]
		);

		// For Debug
		// return 0;
		int index = 0;
		for( i = 0; i < argc; ++i ) {
			if ( cmp_suffix( argv[i], image_suffix, 4, 2 ) ) {
				g_image_names[index] = argv[i];
				IplImage* temp = cvLoadImage( argv[i] );

				// For Debug
				//
				// cout << "argv[" << i << "]: " << argv[i] << endl;
				// cout << "#1" << endl;
				g_images[index] = cvLoadImage( argv[i] );
				// cout << "#2" << endl;
				g_canny_images[index] = cvCreateImage( cvGetSize(temp), temp->depth, temp->nChannels );
				// cout << "#3" << endl;
				g_show_images[index] = cvCreateImage( cvSize(temp->width*3, temp->height), temp->depth, temp->nChannels );
				// cout << "#4" << endl;
				cvZero(g_canny_images[index]);
				cvZero(g_show_images[index]);
				// cout << "#5" << endl;
				++index;
			}
		}

		refresh_image();

		// For Debug
		// return 0;
		while( 1 ) {
			if( cvWaitKey(1) == 27 ) {
				break;
			}
			cvShowImage( "Best Threshold", g_show_images[g_image_now_index] );
		}

		cvDestroyWindow( "Best Threshold" );
		for( i = 0; i < g_image_count; ++i ) {
			cvReleaseImage( &g_images[i] );
		}
	}

	return 0;
}