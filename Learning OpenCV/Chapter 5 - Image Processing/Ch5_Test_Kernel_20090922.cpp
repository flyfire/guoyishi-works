///////////////////////////////////////
// Date:       2009-09-22
// Author:     Yishi Guo
// Chapter:    5
// Page:       118
// Content:    Making Your Own Kernel
///////////////////////////////////////
#include <cv.h>
#include <highgui.h>

int main( int argc, char** argv ) {
	if ( argc >= 2 ) {
		// Create Windows
		//
		cvNamedWindow( "img original", CV_WINDOW_AUTOSIZE );
		cvNamedWindow( "dst1 rectangle cvErode", CV_WINDOW_AUTOSIZE );
		cvNamedWindow( "dst2 cross cvErode", CV_WINDOW_AUTOSIZE );
		cvNamedWindow( "dst3 ellipse cvErode", CV_WINDOW_AUTOSIZE );

		// Get the Images
		//
		IplImage* img = cvLoadImage( argv[1] );
		IplImage* dst1 = cvCreateImage(
			cvSize( img->width, img->height ),
			img->depth,
			img->nChannels
			);
		IplImage* dst2 = cvCloneImage( dst1 );
		IplImage* dst3 = cvCloneImage( dst2 );

		// Create kernels
		// 
		IplConvKernel* kernel1 = cvCreateStructuringElementEx(
			3,               // cols
			3,               // rows
			2,               // anchor_x
			2,               // anchor_y
			CV_SHAPE_RECT,   // shape
			NULL             // values
			);

		IplConvKernel* kernel2 = cvCreateStructuringElementEx(
			3,
			3,
			1,
			1,
			CV_SHAPE_CROSS,
			NULL
			);

		IplConvKernel* kernel3 = cvCreateStructuringElementEx(
			5,
			5,
			2,
			2,
			CV_SHAPE_ELLIPSE,
			NULL
			);

		// Erode
		//
		cvErode(
			img,      // source
			dst1,     // destination
			kernel1,  // kernel
			1         // iterations
			);
		
		cvErode(
			img,
			dst2,
			kernel2,
			1
			);

		cvErode(
			img,
			dst3,
			kernel3,
			1
			);

		// Show Images
		//
		cvShowImage( "img original", img );
		cvShowImage( "dst1 rectangle cvErode", dst1 );
		cvShowImage( "dst2 cross cvErode", dst2 );
		cvShowImage( "dst3 ellipse cvErode", dst3 );

		// Wait a key
		//
		cvWaitKey( 0 );

		// Release Resource
		//
		cvReleaseImage( &img );
		cvReleaseImage( &dst1 );
		cvReleaseImage( &dst2 );
		cvReleaseImage( &dst3 );

		cvReleaseStructuringElement( &kernel1 );
		cvReleaseStructuringElement( &kernel2 );
		cvReleaseStructuringElement( &kernel3 );

		cvDestroyWindow( "img original" );
		cvDestroyWindow( "dst1 rectangle cvErode" );
		cvDestroyWindow( "dst2 cross cvErode" );
		cvDestroyWindow( "dst3 ellipse cvErode" );
	}

	return 0;
}
