/////////////////////////////////////////////
// Date: 2009-10-16
// Author: Yishi Guo
//////////////////////////////////////////////////////////////////////////// Next day!
#include <cv.h>
#include <highgui.h>
#include <iostream.h>

CvRect box = cvRect( 0, 0, 0, 0 );
bool drawing_box = false;
// bool reset_image = false;

void ResetImage( const IplImage* src, IplImage* dst ) {
	cvCopyImage( src, dst );
}

void draw_box( IplImage* img, CvRect rect ) {
	cvRectangle(
		img,
		cvPoint( rect.x, rect.y ),
		cvPoint( rect.x+rect.width, rect.y+rect.height ),
		cvScalar(0x00,0x00,0xff)  // red color
	);
}

void highlight_box( IplImage* img, CvRect rect ) {
	cvSetImageROI( img, rect );
	cvAddS( img, cvScalarAll( 100 ), img );
	cvResetImageROI( img );
}

void data_result( IplImage* img, CvRect rect, IplImage* result ) {
	int data[3][8] = {{0}};
	unsigned char *point;
	for ( int i = 0; i < rect.height; ++i ) {
		for ( int j = 0; j < rect.width; ++j ) {
			point = cvPtr2D( img, rect.y+i, rect.x+j );
			for ( int k = 0; k < 3; ++k ) {
				for( int l = 0; l < 8; ++l ) {
					if ( (int)point[k] <= (l+1)*32-1 &&
						(int)point[k] >= l*32 ) {
						++data[k][l];
					}
				}
				// cout << " " << (int)point[k];
			}
			// cout << endl;
		}
		// cout << endl;
	}

	// For debug
	//

	int width = result->width;
	int height = result->height;
	int max = 0;
	int one = width / 32;

	int m,n;

	// Find max value
	//
	for ( m = 0; m < 3; ++m ) {
		for ( n = 0; n < 8; ++n ) {
			// cout << data[m][n] << " ";
			if ( data[m][n] > max ) {
				max = data[m][n];
			}
		}
		// cout << endl;
	}
	// cout << endl;

	for ( m = 0; m < 3; ++m ) {
		for ( n = 0; n < 8; ++n ) {
			int data_height = data[m][n] * height / max;
			int x = one*n*4 + one*m;
			int y = height - data_height;
			CvScalar color;
			switch ( m ) {
				case 0:
					color = cvScalar( 0xff, 0x00, 0x00 );
					break;
				case 1:
					color = cvScalar( 0x00, 0xff, 0x00 );
					break;
				case 2:
					color = cvScalar( 0x00, 0x00, 0xff );
					break;
			}

			// For debug
			//
			// cout << x << " " << y << " "
			// 	 << one << " " << data_height << endl;

			// CvRect data_rect = cvRect(x, y, one, data_height);

			/*
			cvSetImageROI( result, data_rect );
			cvSet( result, cvScalarAll(23) );
			cvResetImageROI( result );
			*/

			cvRectangle(
				result,
				cvPoint(x,y),
				cvPoint(one+x, data_height+y),
				color,
				CV_FILLED
			);
		}
	}
}


void my_mouse_callback( int event, int x, int y, int flags, void* param ) {

	IplImage* image = (IplImage*)param;

	switch( event ) {
		case CV_EVENT_LBUTTONDOWN: {
			// reset_image = true;
			drawing_box = true;
			box = cvRect( x, y, 0, 0 );
		}
		break;
		case CV_EVENT_MOUSEMOVE: {
			if ( drawing_box ) {
				// reset_image = false;
				box.width = x-box.x;
				box.height = y-box.y;
			}
		}
		break;
		case CV_EVENT_LBUTTONUP: {
			drawing_box = false;
			// reset_image = false;
			if ( box.width < 0 ) {
				box.x += box.width;
				box.width *= -1;
			}
			if ( box.height < 0 ) {
				box.y += box.height;
				box.height *= -1;
			}
			draw_box( image, box );
		}
		break;
	}
}

int main( int argc, char** argv ) {
	if ( argc >= 2 ) {
		IplImage* src = cvLoadImage( argv[1] );
		IplImage* img = cvCloneImage( src );

		cvNamedWindow( "Exercise 4-3", CV_WINDOW_AUTOSIZE );
		cvSetMouseCallback(
			"Exercise 4-3",
			my_mouse_callback,
			(void*)img
		);

		// Part-B:
		//
		IplImage* result = cvCreateImage( cvSize(320, 240), IPL_DEPTH_32F, 3 );
		cvSetZero( result );

		cvNamedWindow( "Exercise 4-3 Result", CV_WINDOW_AUTOSIZE );
		bool show_result = false;

		while ( 1 ) {
			if ( drawing_box ) {
				ResetImage( src, img );
				draw_box( img, box );
				show_result = false;
			} else if ( box.width > 0 && box.height > 0 ) {
				ResetImage( src, img );
				highlight_box( img, box );
				if ( !show_result ) {
					cvSetZero( result );
					data_result( img, box, result );
					cvShowImage( "Exercise 4-3 Result", result );
					show_result = true;
				}
			}

			cvShowImage( "Exercise 4-3", img );

			if ( cvWaitKey(1) == 27 ) {
				break;
			}
		}

		cvReleaseImage( &src );
		cvReleaseImage( &img );
		cvDestroyWindow( "Exercise 4-3" );

		return 0;
	}
	return -1;
}