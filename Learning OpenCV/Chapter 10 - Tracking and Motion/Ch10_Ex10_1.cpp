//////////////////////////////////////////////////////
// Date:       2010-01-24
// Coder:      Yishi Guo
// Copy From:  Example 10-1
// Content:    Example 10-1.
//             Pyramid Lucas-Kanade optical flow code
//////////////////////////////////////////////////////
// Pyramid L-K optical flow example
//
#include <cv.h>
#include <highgui.h>
#include <cxcore.h>
#include <stdio.h>

const int MAX_CORNERS = 500;

int main( int argc, char** argv ) {

	// Initialize, load two images from the file system, and
	// allocate the images and other structures we will need for
	// results.
	//
	IplImage* imgA = cvLoadImage( "OpticalFlow0.jpg", CV_LOAD_IMAGE_GRAYSCALE );
	IplImage* imgB = cvLoadImage( "OpticalFlow1.jpg", CV_LOAD_IMAGE_GRAYSCALE );

	CvSize img_sz = { imgA->width, imgA->height };

	int win_size = 10;

	IplImage* imgC = cvLoadImage( "OpticalFlow1.jpg", CV_LOAD_IMAGE_UNCHANGED );

	// The first thing we need to do is get the features
	// we want to track
	//
	IplImage* eig_image = cvCreateImage( img_sz, IPL_DEPTH_32F, 1 );
	IplImage* tmp_image = cvCreateImage( img_sz, IPL_DEPTH_32F, 1 );

	int corner_count = MAX_CORNERS;
	CvPoint2D32f* cornersA = new CvPoint2D32f[ MAX_CORNERS ];

	cvGoodFeaturesToTrack(
		imgA,
		eig_image,
		tmp_image,
		cornersA,
		&corner_count,
		0.01,
		5.0,
		0,
		3,
		0.04
	);

	cvFindCornerSubPix(
		imgA,
		cornersA,
		corner_count,
		cvSize( win_size, win_size ),
		cvSize( -1, -1 ),
		cvTermCriteria( CV_TERMCRIT_ITER | CV_TERMCRIT_EPS, 20, 0.03 )
	);

	// Call the Lucas Kanade algorithm
	//
	char features_found[ MAX_CORNERS ];
	float feature_errors[ MAX_CORNERS ];

	CvSize pyr_sz = cvSize( imgA->width+8, imgB->height/3 );

	IplImage* pyrA = cvCreateImage( pyr_sz, IPL_DEPTH_32F, 1 );
	IplImage* pyrB = cvCreateImage( pyr_sz, IPL_DEPTH_32F, 1 );

	CvPoint2D32f* cornersB = new CvPoint2D32f[ MAX_CORNERS ];

	cvCalcOpticalFlowPyrLK(
		imgA,
		imgB,
		pyrA,
		pyrB,
		cornersA,
		cornersB,
		corner_count,
		cvSize( win_size, win_size ),
		5,
		features_found,
		feature_errors,
		cvTermCriteria( CV_TERMCRIT_ITER | CV_TERMCRIT_EPS, 20, .3 ),
		0
	);

	// Now make some image of what we are looking at:
	//
	IplImage* imgD = cvCreateImage( img_sz, IPL_DEPTH_8U, 1 );
	cvZero( imgD );

	for ( int i = 0; i < corner_count; i++ ) {
		if ( features_found[i] == 0 || feature_errors[i] > 500 ) {
			printf( "Error is %f\n", feature_errors[i] );
			continue;
		}
		printf( "Got it\n" );
		CvPoint p0 = cvPoint(
			cvRound( cornersA[i].x ),
			cvRound( cornersA[i].y )
		);
		CvPoint p1 = cvPoint(
			cvRound( cornersB[i].x ),
			cvRound( cornersB[i].y )
		);
		cvLine( imgC, p0, p1, CV_RGB(255,0,0), 2 );
		cvLine( imgD, p0, p1, cvScalarAll(255), 2 );
	}

	cvNamedWindow( "ImageA", CV_WINDOW_AUTOSIZE );
	cvNamedWindow( "ImageB", CV_WINDOW_AUTOSIZE );
	cvNamedWindow( "LKpyr_OpticalFlow", CV_WINDOW_AUTOSIZE );
	cvNamedWindow( "ImageD", CV_WINDOW_AUTOSIZE );

	cvShowImage( "ImageA", imgA );
	cvShowImage( "ImageB", imgB );
	cvShowImage( "LKpyr_OpticalFlow", imgC );
	cvShowImage( "ImageD", imgD );

	cvWaitKey( 0 );
	
	cvDestroyWindow( "ImageA" );
	cvDestroyWindow( "ImageB" );
	cvDestroyWindow( "LKpyr_OpticalFlow" );
	cvDestroyWindow( "ImageD" );
	cvReleaseImage( &imgA );
	cvReleaseImage( &imgB );
	cvReleaseImage( &imgC );
	cvReleaseImage( &imgD );
	cvReleaseImage( &eig_image );
	cvReleaseImage( &tmp_image );
	cvReleaseImage( &pyrA );
	cvReleaseImage( &pyrB );

	return 0;
}
