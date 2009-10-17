//////////////////////////////////////////////////////////////////////////
// Date:      2009-10-12
// Coder:     Yishi Guo
// Copy From: Example 8-3
// Content:   Example 8-3.
//            Finding and drawing contours on an input image(continued)
//////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <cv.h>
#include <highgui.h>
#define CVX_RED CV_RGB(0xff, 0x00, 0x00)
#define CVX_BLUE CV_RGB(0x00, 0x00, 0xff)

int main( int argc, char** argv ) {
	cvNamedWindow( argv[0], CV_WINDOW_AUTOSIZE );

	IplImage* img_8uc1 = cvLoadImage( argv[1], CV_LOAD_IMAGE_GRAYSCALE );
	IplImage* img_edge = cvCreateImage( cvGetSize(img_8uc1), 8, 1 );
	IplImage* img_8uc3 = cvCreateImage( cvGetSize(img_8uc1), 8, 3 );

	cvThreshold( img_8uc1, img_edge, 128, 255, CV_THRESH_BINARY );

	CvMemStorage* storage = cvCreateMemStorage();
	CvSeq* first_contour = NULL;

	int Nc = cvFindContours(
		img_edge,
		storage,
		&first_contour,
		sizeof(CvContour),
		CV_RETR_LIST  // Try all four values and see what happens
	);

	int n = 0;
	printf( "Total Contours Detected: %d\n", Nc );
	for ( CvSeq* c = first_contour; c != NULL; c = c->h_next ) {
		cvCvtColor( img_8uc1, img_8uc3, CV_GRAY2BGR );
		cvDrawContours(
			img_8uc3,
			c,
			CVX_RED,
			CVX_BLUE,
			0,  // Try different values of max_level, and see what happens
			2,
			8
		);
		printf( "Contour #%d\n", n );
		cvShowImage( argv[0], img_8uc3 );
		printf( " %d elements:\n", c->total );
		for( int i = 0; i < c->total; ++i ) {
			CvPoint *p = CV_GET_SEQ_ELEM( CvPoint, c, i );
			printf( " (%d,%d)\n", p->x, p->y );
		}
		cvWaitKey(0);
		n++;
	}

	printf("Finished all contours.\n");
	cvCvtColor( img_8uc1, img_8uc3, CV_GRAY2BGR );
	cvShowImage( argv[0], img_8uc3 );
	cvWaitKey(0);

	cvDestroyWindow( argv[0] );

	cvReleaseImage( &img_8uc1 );
	cvReleaseImage( &img_8uc3 );
	cvReleaseImage( &img_edge );

	return 0;
}