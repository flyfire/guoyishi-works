/////////////////////////////////////////////////////
// Date:     2009-10-02
// Coder:    Yishi Guo
// Copy:     Example 6-1
// Chapter:  6
// Page:     161
// Content:  cvHoughCircles | Image Transforms
/////////////////////////////////////////////////////
#include <cv.h>
#include <highgui.h>
#include <math.h>

int main( int argc, char** argv ) {
	// Load Image
	// 
	IplImage* image = cvLoadImage(
		argv[1],
		CV_LOAD_IMAGE_GRAYSCALE
		);

	CvMemStorage* storage = cvCreateMemStorage(0);
	
	// Smooth the image
	//
	cvSmooth( image, image, CV_GAUSSIAN, 5, 5 );

	// Get the Hough circles
	//
	CvSeq* results = cvHoughCircles(
		image,
		storage,
		CV_HOUGH_GRADIENT,
		2,
		image->width/10
		);

	// Draw circles
	//
	for ( int i = 0; i < results->total; i++ ) {
		float *p = (float*) cvGetSeqElem( results, i );
		CvPoint pt = cvPoint( cvRound( p[0] ), cvRound( p[1] ) );
		cvCircle(
			image,
			pt,
			cvRound( p[2] ),
			CV_RGB( 255, 0, 0 ),
			3,
			8
			);
	}
	
	// Show the image
	// 
	cvNamedWindow( "cvHoughCircles", CV_WINDOW_AUTOSIZE );
	cvShowImage( "cvHoughCircles", image );
	cvWaitKey(0);

	// Clear resources
	// 
	cvReleaseImage( &image );
	cvDestroyWindow( "cvHoughCircles" );

	return 0;
}
