////////////////////////////////////////
// Date: 2010-01-13
// Coder: Yishi Guo
// Copy From: http://www.opencv.org.cn/forum/viewtopic.php?f=1&t=4648&start=0
// About: cvRunningAvg()
////////////////////////////////////////
#include <stdio.h>
#include "cv.h"
#include "highgui.h"

int main( int argc, char** argv ) {
	IplImage *pFrame = NULL;
	IplImage *pFrImg = NULL;
	IplImage *pBkImg = NULL;

	CvMat *pFrameMat = NULL;
	CvMat *pFrMat = NULL;
	CvMat *pBkMat = NULL;

	CvCapture *pCapture;

	int nFrmNum = 0;

	cvNamedWindow( "video", CV_WINDOW_AUTOSIZE );
	cvNamedWindow( "background", CV_WINDOW_AUTOSIZE );
	cvNamedWindow( "foreground", CV_WINDOW_AUTOSIZE );

	cvMoveWindow( "video", 30, 0 );
	cvMoveWindow( "background", 360, 0 );
	cvMoveWindow( "foreground", 690, 0 );

	if ( argc < 2 ) {
		pCapture = cvCreateCameraCapture( 0 );
	} else if ( !(pCapture = cvCaptureFromFile( argv[1] ) ) ) {
		fprintf( stderr, "Can not open video file %s\n", argv[1] );
		return -2;
	}

	while ( pFrame = cvQueryFrame( pCapture ) ) {
		nFrmNum++;

		if ( nFrmNum == 1 ) {
			CvSize sz = cvSize( pFrame->width, pFrame->height );
			pBkImg = cvCreateImage( sz, IPL_DEPTH_8U, 1 );
			pFrImg = cvCreateImage( sz, IPL_DEPTH_8U, 1 );
			pBkMat = cvCreateMat( pFrame->height, pFrame->width, CV_32FC1 );
			pFrMat = cvCreateMat( pFrame->height, pFrame->width, CV_32FC1 );
			pFrameMat = cvCreateMat( pFrame->height, pFrame->width, CV_32FC1 );

			cvCvtColor( pFrame, pBkImg, CV_BGR2GRAY );
			cvCvtColor( pFrame, pFrImg, CV_BGR2GRAY );

			cvConvert( pFrImg, pFrameMat );
			cvConvert( pFrImg, pFrMat );
			cvConvert( pFrImg, pBkMat );
		} else {
			cvCvtColor( pFrame, pFrImg, CV_BGR2GRAY );
			cvConvert( pFrImg, pFrameMat );
			cvSmooth( pFrameMat, pFrameMat, CV_GAUSSIAN, 3, 0, 0, 0 );

			cvAbsDiff( pFrameMat, pBkMat, pFrMat );

			cvThreshold( pFrMat, pFrImg, 60, 255.0, CV_THRESH_BINARY );

			cvErode( pFrImg, pFrImg, 0, 1 );
			cvDilate( pFrImg, pFrImg, 0, 1 );

			// This is the important function
			cvRunningAvg( pFrameMat, pBkMat, 0.2, 0 );
			cvConvert( pBkMat, pBkImg );

			cvShowImage( "video", pFrame );
			cvShowImage( "background", pBkImg );
			cvShowImage( "foreground", pFrImg );

			if ( cvWaitKey( 33 ) >= 0 ) break;

		}
	}

	cvReleaseCapture( &pCapture );

	cvDestroyWindow( "video" );
	cvDestroyWindow( "background" );
	cvDestroyWindow( "foreground" );

	cvReleaseImage( &pFrame );
	cvReleaseImage( &pFrImg );
	cvReleaseImage( &pBkImg );

	cvReleaseMat( &pFrameMat );
	cvReleaseMat( &pFrMat );
	cvReleaseMat( &pBkMat );

	return 0;
}