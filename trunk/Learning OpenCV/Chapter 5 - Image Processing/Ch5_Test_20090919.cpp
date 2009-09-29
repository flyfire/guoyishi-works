//////////////////////////////////////////////
// Date: 2009-09-19
// Author: Yishi Guo
// Chapter: 5
//////////////////////////////////////////////
#include <cv.h>
#include <highgui.h>

int main( int argc, char** argv ) {
	if ( argc >= 2 ) {

		// Create New Windows
		//
		cvNamedWindow( "Src", CV_WINDOW_AUTOSIZE );
		cvNamedWindow( "CV_GAUSSIAN", CV_WINDOW_AUTOSIZE );
		cvNamedWindow( "CV_BLUR", CV_WINDOW_AUTOSIZE );
		// cvNamedWindow( "CV_BLUR_NO_SCALE", CV_WINDOW_AUTOSIZE );
		cvNamedWindow( "CV_MEDIAN", CV_WINDOW_AUTOSIZE );
		cvNamedWindow( "CV_BILATERAL", CV_WINDOW_AUTOSIZE );

		// Create Images
		//
		IplImage* img = cvLoadImage( argv[1] );
		IplImage* dst_gaussian = cvCreateImage( cvSize(img->width, img->height), img->depth, img->nChannels );
		IplImage* dst_blur = cvCreateImage( cvSize(img->width, img->height), img->depth, img->nChannels );
		// IplImage* dst_blur_no_scale = cvCreateImage( cvSize(img->width, img->height), img->depth, img->nChannels );
		IplImage* dst_median = cvCreateImage( cvSize(img->width, img->height), img->depth, img->nChannels );
		IplImage* dst_bilateral = cvCreateImage( cvSize(img->width, img->height), img->depth, img->nChannels );

		// Action
		//
		cvSmooth( img, dst_gaussian, CV_GAUSSIAN, 9, 0, 0, 0 );
		cvSmooth( img, dst_blur, CV_BLUR, 9, 0, 0, 0 );
		// cvSmooth( img, dst_blur_no_scale, CV_BLUR_NO_SCALE);
		cvSmooth( img, dst_median, CV_MEDIAN, 9, 0, 0, 0 );
		cvSmooth( img, dst_bilateral, CV_BILATERAL, 9 );  ///////////////////////////// Could Not Work!

		// Show Images
		//
		cvShowImage( "Src", img );
		cvShowImage( "CV_GAUSSIAN", dst_gaussian );
		cvShowImage( "CV_BLUR", dst_blur );
		// cvShowImage( "CV_BLUR_NO_SCALE", dst_blur_no_scale );
		cvShowImage( "CV_MEDIAN", dst_median );
		cvShowImage( "CV_BILATERAL", dst_bilateral );

		cvWaitKey( 0 );

		// Release Resources
		cvReleaseImage( &img );
		cvReleaseImage( &dst_gaussian );
		cvReleaseImage( &dst_blur );
		// cvReleaseImage( &dst_blur_no_scale );
		cvReleaseImage( &dst_median );
		cvReleaseImage( &dst_bilateral );

		cvDestroyWindow( "Src" );
		cvDestroyWindow( "CV_GAUSSIAN" );
		cvDestroyWindow( "CV_BLUR" );
		// cvDestroyWindow( "CV_BLUR_NO_SCALE" );
		cvDestroyWindow( "CV_MEDIAN" );
		cvDestroyWindow( "CV_BILATERAL" );
	} else {

	}

	return 0;
}
