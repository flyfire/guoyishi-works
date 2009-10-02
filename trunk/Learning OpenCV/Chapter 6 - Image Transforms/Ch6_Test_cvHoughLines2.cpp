////////////////////////////////////////////////////
// Date: 2009-10-02
// Coder: Yishi Guo
// Copy From: OpenCV: Image Processing and Computer Vision Reference Manual
// Chapter: 6
// Content: cvHoughLines2 | Image Transforms
// Page: 156
////////////////////////////////////////////////////
#include <cv.h>
#include <highgui.h>

int main(int argc, char** argv) {
	if ( argc >= 2 ) {
		// Initialize variables
		//
		IplImage* src = cvLoadImage( argv[1], CV_LOAD_IMAGE_GRAYSCALE );
		IplImage* dst = cvCreateImage( cvGetSize(src), src->depth, 1 );
		IplImage* color_dst = cvCreateImage( cvGetSize(src), IPL_DEPTH_8U, 3 );

		CvMemStorage* storage = cvCreateMemStorage(0);
		CvSeq* lines = 0;
		int i = 0;

		// Do something on the image
		// 
		if ( argc >= 4 ) {
			cvCanny( src, dst, atoi(argv[2]), atoi(argv[3]), 3 );
		} else {
			cvCanny( src, dst, 50, 200, 3 );
		}
		cvCvtColor( dst, color_dst, CV_GRAY2BGR );

		// cvHoughLines2
		// 
		if ( argc >= 9 ) {
			lines = cvHoughLines2( dst, storage, CV_HOUGH_PROBABILISTIC, atoi(argv[4]),
				                   atof(argv[5]), atoi(argv[6]), atoi(argv[7]), atoi(argv[8]) );
		} else {
			lines = cvHoughLines2( dst, storage, CV_HOUGH_PROBABILISTIC, 1, CV_PI/180, 50, 50, 10 );
		}

		// Draw lines on the image
		//
		for( i = 0; i < lines->total; i++ ) {
			CvPoint* line = (CvPoint*)cvGetSeqElem(lines, i);
			cvLine( color_dst, line[0], line[1], CV_RGB(255, 0, 0), 3, 8 );
		}

		cvNamedWindow("Source", 1 );
		cvShowImage( "Source", src );

		cvNamedWindow( "Hough", 1 );
		cvShowImage( "Hough", color_dst );

		cvWaitKey(0);

		// Clear resources
		// 
		cvReleaseImage( &src );
		cvReleaseImage( &dst );
		cvReleaseImage( &color_dst );

		cvDestroyWindow( "Source" );
		cvDestroyWindow( "Hough" );
	}
	return 0;
}