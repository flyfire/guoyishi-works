////////////////////////////////
// Yishi Guo
// 20090910
////////////////////////////////
// roi_add <image> <x> <y> <width> <height> <add>
#include <cv.h>
#include <highgui.h>

int main (int argc, char** argv) {
	IplImage* src;
	cvNamedWindow("Example3_12_pre", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("Example3_12_post", CV_WINDOW_AUTOSIZE);
	if ( argc == 7 && ((src = cvLoadImage(argv[1], 1)) != 0)) {
		int x = atoi(argv[2]);
		int y = atoi(argv[3]);
		int width = atoi(argv[4]);
		int height = atoi(argv[5]);
		int add = atoi(argv[6]);
		cvShowImage( "Example3_12_pre", src );
		cvSetImageROI(src, cvRect(x, y, width, height));
		cvAddS(src, cvScalar(add), src);
		cvResetImageROI(src);
		// cvNamedWindow( "Roi_add", 1 );
		cvShowImage( "Example3_12_post", src );
		cvWaitKey();
	}
	cvReleaseImage( &src );
	cvDestroyWindow( "Example3_12_pre" );
	cvDestroyWindow( "Example3_12_post" );
	return 0;
}