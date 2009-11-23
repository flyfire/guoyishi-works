///////////////////////////////////////////////////////////////////////
// Date:      2009-10-20
// Coder:     Yishi Guo
// Copy From: Example 9-1
// Chapter:   9 - Image Parts and Segmentation
// Page:      269p
// Content:   Example 9-1. Reading out the RGB values of all pixels
//            in one row of a video and accumulating those values
//            into three separate files
///////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <cv.h>
#include <highgui.h>

void help() {
	printf("\nRead out RGB pixel values and store them to disk\nCall:\n"
		"./Ex_9_1 avi_file\n"
		"\n This will store to files blines.csv glines.csv and rlines.csv\n\n");
}

int main( int argc, char** argv ) {
	if (argc != 2) {help(); return -1;}
	cvNamedWindow( "Example_9_1", CV_WINDOW_AUTOSIZE );
	CvCapture* capture = cvCreateFileCapture( argv[1] );
	if (!capture) {printf("\nCouldn't open %s\n", argv[1]); help(); return -1;}
	CvPoint pt1 = cvPoint(10, 10);
	CvPoint pt2 = cvPoint(20, 20);

	int max_buffer;
	IplImage *rawImage;

	int r[10000], g[10000], b[10000];
	FILE *fptrb = fopen("blines.csv", "w");  // Store the data here
	FILE *fptrg = fopen("glines.csv", "w");
	FILE *fptrr = fopen("rlines.csv", "w");
	CvLineIterator iterator;

	// MAIN PROCESSING LOOP:
	for(;;) {
		if ( !cvGrabFrame( capture ))
			break;
		rawImage = cvRetrieveFrame( capture );
		max_buffer = cvInitLineIterator(rawImage, pt1, pt2, &iterator, 8, 0);
		cvShowImage( "Example_9_1", rawImage );
		int c = cvWaitKey(10);
		for(int j = 0; j < max_buffer; j++ ) {
			fprintf(fptrb, "%d, ", iterator.ptr[0]);
			fprintf(fptrg, "%d, ", iterator.ptr[1]);
			fprintf(fptrr, "%d, ", iterator.ptr[2]);
			iterator.ptr[2] = 255;  // Mark this sample in red
			CV_NEXT_LINE_POINT(iterator);
		}

		// OUTPUT THE DATA IN ROWS:
		fprintf(fptrb,"\n"); fprintf(fptrg, "\n"); fprintf(fptrr, "\n");
	}
	// CLEANUP:
	printf("\nData stored to files: blines.csv, glines.csv and rlines.csv\n\n");
	fclose(fptrb); fclose(fptrg); fclose(fptrr);
	cvReleaseCapture( &capture );
	cvDestroyWindow( "Example_9_1" );
}