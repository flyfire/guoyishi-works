///////////////////////////////////////////////////////////////////////
// Date:      2009-11-02
// Author:    Yishi Guo
// Exercise:  5-12
// Chapter:   5 Image Processing
// Page:      143p
// Usage:     Exercise_5_12 src_image --adaptive=ture param1_value
// Content:   cvThreshold(), cvAdaptiveThreshold()
///////////////////////////////////////////////////////////////////////
#include "cv.h"
#include "highgui.h"
#define IMAGE_NUMBER 5

int main( int argc, char** argv ) {
	if ( argc < 2 ) {
		return -1;
	} else {
		const char* is_adaptive_opt = "--adaptive=";
		int is_adaptive_opt_len = strlen( is_adaptive_opt );

		bool is_adaptive = false;
		int i;
		for ( i = 0; i < argc; ++i ) {
			if ( strncmp( argv[i], is_adaptive_opt, is_adaptive_opt_len ) == 0 
				&& strncmp( argv[i]+is_adaptive_opt_len, "true", 4 ) == 0 ) {
				is_adaptive = true;
			}
		}

		IplImage* src = cvLoadImage( argv[1], CV_LOAD_IMAGE_GRAYSCALE );
		if ( !src ) {
			return -1;
		}

		cvNamedWindow( "Exercise 5-12 Source Image", CV_WINDOW_AUTOSIZE );
		cvShowImage( "Exercise 5-12 Source Image", src );

		IplImage** imgs = new IplImage*[IMAGE_NUMBER];

		double threshold = 128;
		double max_value = 255;
		int adaptive_method = CV_ADAPTIVE_THRESH_MEAN_C;
		int threshold_type = 0;
		int block_size = 3;
		double param1 = 5;
		if ( is_adaptive && argc > 3 ) {
			param1 = atoi(argv[3]);
		}

		for ( i = 0; i < IMAGE_NUMBER; ++i ) {
			if ( is_adaptive && i > 1 ) {
				break;
			}

			imgs[i] = cvCreateImage( cvGetSize(src), IPL_DEPTH_8U, 1 );
			char* window_name;
			switch ( i ) {
				case 1:
					threshold_type = CV_THRESH_BINARY_INV;
					window_name = "Exercise 5-12 CV_THRESH_BINARY_INV";
					break;
				case 2:
					threshold_type = CV_THRESH_TRUNC;
					window_name = "Exercise 5-12 CV_THRESH_TRUNC";
					break;
				case 3:
					threshold_type = CV_THRESH_TOZERO_INV;
					window_name = "Exercise 5-12 CV_THRESH_TOZERO_INV";
					break;
				case 4:
					threshold_type = CV_THRESH_TOZERO;
					window_name = "Exercise 5-12 CV_THRESH_TOZERO";
					break;
				case 0:
				default:
					threshold_type = CV_THRESH_BINARY;
					window_name = "Exercise 5-12 CV_THRESH_BINARY";
					break;
			}

			cvNamedWindow( window_name, CV_WINDOW_AUTOSIZE );

			if ( is_adaptive ) {
				cvAdaptiveThreshold( src, imgs[i], max_value, adaptive_method, threshold_type, block_size, param1 );
			} else {
				cvThreshold( src, imgs[i], threshold, max_value, threshold_type );
			}

			cvShowImage( window_name, imgs[i] );
		}

		cvWaitKey(0);

		// Release Resources
		//
		for ( i = 0; i < IMAGE_NUMBER; ++i ) {
			if ( is_adaptive && i > 1 ) {
				break;
			}
			cvReleaseImage( &imgs[i] );
		}
		cvReleaseImage( &src );

		cvDestroyAllWindows();

	}
	return 0;
}