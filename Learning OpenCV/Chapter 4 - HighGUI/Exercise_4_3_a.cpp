#include <cv.h>
#include <highgui.h>

CvRect box;
bool drawing_box = false;
bool drawn_box = false;

void highlight_region(
	IplImage* image,
	CvRect box
	) {

	CvScalar highlight_color = CV_RGB( 100, 100, 100 );
	CvScalar border_color = CV_RGB( 20, 20, 100 );

	cvRectangle(
		image,
		cvPoint(box.x, box.y),
		cvPoint(box.x+box.width, box.y+box.height),
		border_color
	);

	cvSetImageROI ( image, box );
	// cvAddS( image, highlight_color, image );

	cvResetImageROI ( image );
}

void my_mouse_callback(
	int event, int x, int y, int flags, void* param
	) {
	IplImage* image = (IplImage*) param;

	switch ( event ) {
		case CV_EVENT_MOUSEMOVE: {
			if ( drawing_box ) {
				drawn_box = false;

				box.width = x - box.x;
				box.height = y - box.y;
			}
		}
		break;
		case CV_EVENT_LBUTTONDOWN: {
			drawing_box = true;
			// drawn_box = false;
			box = cvRect( x, y, 0, 0 );
		}
		break;
		case CV_EVENT_LBUTTONUP: {
			drawing_box = false;
			drawn_box = true;
			if ( box.width < 0 ) {
				box.x += box.width;
				box.width *= -1;
			}
			if ( box.height < 0 ) {
				box.y += box.height;
				box.height *= -1;
			}
			highlight_region( image, box );
		}
		break;
	}
}

int main( int argc, char** argv ) {
	if ( argc >= 2 ) {
		cvNamedWindow( argv[1], CV_WINDOW_AUTOSIZE );

		IplImage* img = cvLoadImage( argv[1] );
		IplImage* temp = cvCreateImage(
			cvSize(img->width, img->height),
			img->depth,
			img->nChannels
		);

		cvCopyImage( img, temp );
	
		cvSetMouseCallback(
			argv[1],
			my_mouse_callback,
			(void*) temp
		);

		while ( 1 ) {
			if ( drawn_box ) {
				highlight_region( temp, box );
			}
			if ( drawing_box) {
				cvCopyImage( img, temp );

				// highlight_region( temp, box );
			}

			cvShowImage( argv[1], temp );

			if ( cvWaitKey( 33 ) == 27 ) {
				break;
			}
		}

		cvReleaseImage( &img );
		cvReleaseImage( &temp );
		cvDestroyWindow( argv[1] );
	} else {
		exit( 0 );
	}

	return 0;
}