//////////////////////////////////////////////////
// Example 4-3. Unpacking a four-character code
// to identify a video codec
// Editor: Yishi Guo
// Date: 20090913
//////////////////////////////////////////////////

#include <cv.h>
#include <highgui.h>
#include <stdio.h>

int main(int argc, char** argv) {
	// Adding something to open a video so that we can read its properties...
	IplImage* frame;	// To hold movie images
	CvCapture* capture = NULL;
	if ((argc < 2) || !(capture = cvCreateFileCapture( argv[1] ))) {
		printf("Failed to open %s\n", argv[1]);
	} else if (!(capture = cvCreateCameraCapture(-1) )) {
		printf("failed to open camera");
		return -1;
	}

	// Read the properties
	double f = cvGetCaptureProperty(
		capture,
		CV_CAP_PROP_FOURCC
	);
	// Debug test
	// printf("%f", f);
	char* fourcc = (char*) (&f);
	printf("Properties of %s are:\n", argc < 2 ? "camera" : argv[1]);
	printf("FOURCC = %c | %c | %c | %c |\n", fourcc[0], fourcc[1], fourcc[2], fourcc[3]);
	cvReleaseCapture( &capture );
	return 0;
}
