#include <cv.h>
#include <highgui.h>

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
using namespace std;

bool is_down = false;
CvPoint down_point = cvPoint( 0, 0 );
uchar* data = NULL;
int step = NULL;

string i2str( const int i ) {
	stringstream newstr;
	newstr << i;
	return newstr.str();
}

void my_mouse_callback(
	int event, int x, int y, int flags, void* param
);

void putText( IplImage* img, CvPoint point ) {

	// CvScalar point_color = cvGet2D( img, point.x, point.y );

	int B = data[point.x * step + point.y + 0];
	int G = data[point.x * step + point.y + 1];
	int R = data[point.x * step + point.y + 2];

	// cout << R << ", " << G << ", " << B << endl;
	// cout << "(" << point.x << ", " << point.y << ")" << endl;

	string str = "(";
	str += i2str(point.x) + ", " + i2str(point.y) + ")";
	str += ":(" + i2str(B) + ", " + i2str(G) + ", " + i2str(R) + ")";

	CvFont font;
	CvScalar color = CV_RGB( 255, 255, 255 );
	cvInitFont(
		&font,
		CV_FONT_HERSHEY_SIMPLEX,
		0.5,
		0.5
	);

	/////////////////////////////////////////////////////
	const char* text = str.c_str();

	cvPutText(
		img,
		text,
		point,
		&font,
		color
	);
}


int main( int argc, char** argv ) {
	if ( argc >= 2 ) {
		char* img_name = argv[1];
		cvNamedWindow( img_name, CV_WINDOW_AUTOSIZE );
		IplImage* image = cvLoadImage( img_name );
		IplImage* temp = cvCloneImage( image );

		step = image->widthStep / sizeof(uchar);
		data = (uchar*)image->imageData;

		cvSetMouseCallback(
			img_name,
			my_mouse_callback,
			(void*) image
		);

		while ( 1 ) {
			if ( is_down ) {
				cvCopy( image, temp );
				putText( temp, down_point );

				// for debug
				// printf("down\n");
			}
			cvShowImage( img_name, temp );
			if ( cvWaitKey( 1 ) == 27 ) break;
		}

		cvReleaseImage( &image );
		cvReleaseImage( &temp );
		cvDestroyWindow( img_name );
	}

	return ( 0 );
}

void my_mouse_callback(
	int event, int x, int y, int flags, void* param
	) {
	IplImage* image = (IplImage*) param;

	switch ( event ) {
		case CV_EVENT_LBUTTONDOWN: {
			is_down = true;
			if ( x < 0 ) x = 0;
			if ( y < 0 ) y = 0;
			down_point.x = x;
			down_point.y = y;
			
			// for debug
			// printf("____down___\n");
		}
		break;

		case CV_EVENT_LBUTTONUP: {
			is_down = false;

			// for debug
			// printf("____up____\n");
		}
		break;

		case CV_EVENT_MOUSEMOVE: {
			if ( is_down ) {
				if ( x < 0 ) x = 0;
				if ( y < 0 ) y = 0;

				down_point.x = x;
				down_point.y = y;
			}
		};
		break;
	}
}
