///////////////////////////////////////////////////////
// Date:      2009-10-29
// Author:    Yishi Guo
// Exercise:  5.6
// Chapter:   5 Image Processing
// Page:      142p
// Content:   cvFloodFill
///////////////////////////////////////////////////////
#include "cv.h"
#include "highgui.h"
#include <iostream.h>

int main( int argc, char** argv ) {
	if( argc < 2 ) {
		return -1;
	} else {
		IplImage* src = cvLoadImage( argv[1], CV_LOAD_IMAGE_GRAYSCALE );
		if( !src ) {
			return -1;
		}

		cvNamedWindow( "src", CV_WINDOW_AUTOSIZE );
		cvShowImage( "src", src );

		IplImage* img = cvCloneImage( src );

		CvPoint largest_point;     // The largest region point
		double largest_area = 0.0; // The largest region area
		CvConnectedComp comp;
		bool is_first = true;      //

		int i,j;
		for( i = 0; i < img->width; ++i ) {
			for( j = 0; j < img->height; ++j ) {

				// For Debug
				// cout << "(" << i << "," << j << ")" << endl;

				uchar value = ((uchar*)(img->imageData + img->widthStep*j))[i];
				if( value == 255) {

					// "Flood fill it using a value of 100"
					cvFloodFill( img, cvPoint(i,j), cvScalarAll(100), cvScalarAll(10), cvScalarAll(10), &comp );

					// For Debug
					// cout << "Area: " << comp.area << endl;
					// cout << "(x,y) = (" << i << "," << j << ")" << endl;

					if ( comp.area > largest_area ) {
						if( !is_first ) {
							cvFloodFill( img, largest_point, cvScalarAll(0) );
						} else {
							is_first = false;
						}

						largest_area = comp.area;

						largest_point.x = i;
						largest_point.y = j;
					} else {
						cvFloodFill( img, cvPoint(i,j), cvScalarAll(0) );
					}
				}
			}
		}

		// "Finally, fill the remaining largest region with 255."
		cvFloodFill( img, largest_point, cvScalarAll(255) );

		cvNamedWindow( "img", CV_WINDOW_AUTOSIZE );
		cvShowImage( "img", img );

		cvWaitKey(0);

		// Save the image
		// 2009-10-29
		// 
		if( argc > 2 ) {
			const char* save_name = argv[2];
			cvSaveImage( save_name, img );
		}

		cvReleaseImage( &src );
		cvReleaseImage( &img );
		cvDestroyWindow( "src" );
		cvDestroyWindow( "img" );
		
	}
	return 0;
}