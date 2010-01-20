//////////////////////////////////////////////
// Date: 2010-01-20
// Coder: Yishi Guo
// Copy & Inspire From: F:\CODE\LearningOpenCV_Code\ch9_watershed.cpp
//////////////////////////////////////////////
#include "cv.h"
#include "highgui.h"
#include <stdio.h>
#include <stdlib.h>

IplImage* marker_mask = 0;
IplImage* img0 = 0, *img = 0, *dst = 0;
CvPoint prev_pt = { -1, -1 };

double inpaintRadius = 3;
int flags = 0;

void on_mouse( int event, int x, int y, int flag, void* param ) {
	if ( !img )
		return;

	if ( event == CV_EVENT_LBUTTONUP || !(flag & CV_EVENT_FLAG_LBUTTON ) )
		prev_pt = cvPoint( -1, -1 );
	else if ( event == CV_EVENT_LBUTTONDOWN )
		prev_pt = cvPoint( x, y );
	else if ( event == CV_EVENT_MOUSEMOVE && (flag & CV_EVENT_FLAG_LBUTTON ) ) {
		CvPoint pt = cvPoint( x, y );
		if ( prev_pt.x < 0 )
			prev_pt = pt;
		cvLine( marker_mask, prev_pt, pt, cvScalarAll( 255 ), 5, 8, 0 );
		cvLine( img, prev_pt, pt, cvScalarAll( 255 ), 5, 8, 0 );
		prev_pt = pt;
		cvShowImage( "image", img );
	}
}

int main( int argc, char** argv ) {
	char* filename = argc >= 2 ? argv[1] : (char*)"fruits.jpg";
	CvRNG rng = cvRNG( -1 );

	if ( ( img0 = cvLoadImage( filename, 1 ) ) == 0 ) {
		printf( "Could not load image!\n" );
		return 0;
	}

	inpaintRadius = argc >= 3 ? atoi( argv[2] ) : 3;
	flags = argc >= 4 ? atoi( argv[3] ) : 0;

	printf( "Hot keys: \n"
		    "\tESC - quit the program\n"
			"\tr - restore the original image\n"
			"\t0 - CV_INPAINT_NS, 1 - CV_INPAINT_TELEA\n"
			"\ti or ENTER - run inpaint algorithm\n"
			"\t\t(before running it, roughly mark the areas on the image)\n"
			"\t\t(before that, roughly outline several markers on the image)\n" );

	cvNamedWindow( "original", CV_WINDOW_AUTOSIZE );
	cvNamedWindow( "image", CV_WINDOW_AUTOSIZE );
	cvNamedWindow( "image repair by inpainting", CV_WINDOW_AUTOSIZE );

	img = cvCloneImage( img0 );
	dst = cvCloneImage( img0 );
	marker_mask = cvCreateImage( cvGetSize(img), 8, 1 );
	
	cvCvtColor( img, marker_mask, CV_BGR2GRAY );

	cvZero( marker_mask );
	cvZero( dst );

	cvShowImage( "original", img0 );
	cvShowImage( "image", img );
	cvShowImage( "image repair by inpainting", dst );

	cvSetMouseCallback( "image", on_mouse, 0 );

	for ( ; ; ) {
		int c = cvWaitKey( 0 );

		if ( (char)c == 27 )
			break;

		if ( (char)c == 'r' ) {
			cvZero( marker_mask );
			cvCopy( img0, img );
			cvShowImage( "image", img );
		}

		if ( (char)c == '0' ) {
			flags = CV_INPAINT_NS;
			printf( "Use CV_INPAINT_NS(Navier-Stokes method)\n" );
		}
		if ( (char)c == '1' ) {
			flags = CV_INPAINT_TELEA;
			printf( "Use CV_INPAINT_TELEA(A.Telea's method)\n" );
		}

		if ( (char)c == 'i' || (char)c == '\n' ) {

			{
				double t = (double)cvGetTickCount();
				cvInpaint( img0, marker_mask, dst, inpaintRadius, flags );
				t = (double)cvGetTickCount() - t;
				printf( "exec time = %gms\n", t/(cvGetTickFrequency()*1000.) );
			}

			cvShowImage( "image repair by inpainting", dst );
		}
	}

	cvReleaseImage( &img0 );
	cvReleaseImage( &img );
	cvReleaseImage( &dst );
	cvReleaseImage( &marker_mask );
	cvDestroyWindow( "original" );
	cvDestroyWindow( "image" );
	cvDestroyWindow( "image repair by inpainting" );

	return 1;
}