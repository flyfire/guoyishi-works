/////////////////////////////////////////////////////////////////////////////
// Date:       2009-10-06
// Coder:      Yishi Guo
// Copy From:  Example 7-3. Creating signatures form histograms for EMD
// Chapter:    6
// Page:       208
// Content:    Earth Mover's Distance | Some More Complicated Stuff
/////////////////////////////////////////////////////////////////////////////
#include <cv.h>
#include <cxcore.h>
#include <highgui.h>
#include <stdio.h>

void help() {
	printf("\nCall is:\n"
		   "Ex_7_1 modelImage0 testImage1 testImage2 dadImage3\n\n");
	printf(
		"  Note that the model image is split in half. Top half(0) makes model. It's then tested\n"
		"  against its lower half(0), testImages 1 and 2 in different lighting and diferent object 3\n\n");
}

int main( int argc, char** argv ) {
	
	IplImage* src[5], *tmp;
	int i;
	if ( argc == 5 ) {
		if (( tmp = cvLoadImage( argv[1], 1 )) == 0 ) {
			printf( "Error on reading iamge 1, %s", argv[1]);
			help();
			return (-1);
		}

		printf("Getting size [[%d] [%d]]\n", tmp->width, tmp->height);
		CvSize size = cvGetSize( tmp );
		printf("Get size %d %d\n", size.width, size.height);
		int width = size.width;
		int height = size.height;
		int halfheight = height >> 1;
		src[0] = cvCreateImage( cvSize(width, halfheight), 8, 3 );
		src[1] = cvCreateImage( cvSize(width, halfheight), 8, 3 );
		if (src[0]->widthStep != tmp->widthStep) {
			printf("Error. Widthstep of alloated src doesn't equal widthStep of loaded image [%d vs %d]",
				src[0]->widthStep, tmp->widthStep);
			help();
			return (-2);
		}

		int widthStep = tmp->widthStep;
		unsigned char *p = (unsigned char*) (tmp->imageData);
		unsigned char *sp = (unsigned char*) (src[0]->imageData);
		for(i = 0; i < widthStep*halfheight; ++i ) {
			*sp++ = *p++;
		}

		sp = (unsigned char*)(src[1]->imageData);
		for( i = 0; i < widthStep*halfheight; ++i ) {  // Bottom half
			*sp++ = *p++;
		}

		// LOAD THE OTHER THERE IMAGES
		for( i = 2; i < 5; ++i ) {
			if (( src[i] = cvLoadImage( argv[i], 1 )) == 0 ) {
				printf("Error on reading image %d: %s\n", i, argv[i] );
				help();
				return (-1);
			}
		}

		// Compute the HSV image, and decompose it into separate planes
		//
		IplImage *hsv[5], *h_plane[5], *s_plane[5], *v_plane[5], *planes[5][2];
		IplImage* hist_img[5];
		CvHistogram* hist[5];
		int h_bins = 8, s_bins = 8;
		int hist_size[] = { h_bins, s_bins };
		float h_ranges[] = { 0, 180 };  // hue is [0, 180]
		float s_ranges[] = { 0, 255 };
		float* ranges[] = { h_ranges, s_ranges };
		int scale = 10;
		for (i = 0; i < 5; ++i) {
			hsv[i] = cvCreateImage( cvGetSize(src[i]), 8, 3 );
			cvCvtColor( src[i], hsv[i], CV_BGR2HSV );

			h_plane[i] = cvCreateImage( cvGetSize( src[i] ), 8, 1 );
			s_plane[i] = cvCreateImage( cvGetSize( src[i] ), 8, 1 );
			v_plane[i] = cvCreateImage( cvGetSize( src[i] ), 8, 1 );
			planes[i][0] = h_plane[i];
			planes[i][1] = s_plane[i];
			cvCvtPixToPlane( hsv[i], h_plane[i], s_plane[i], v_plane[i], 0 );
			// Build the histogram and compute ites contents.
			//
			{
				hist[i] = cvCreateHist(
					2,
					hist_size,
					CV_HIST_ARRAY,
					ranges,
					1
					);
			}
			cvCalcHist( planes[i], hist[i], 0, 0 );
			cvNormalizeHist( hist[i], 1.0 );

			// Create an image to use to visualize our histogram
			//
			hist_img[i] = cvCreateImage(
				cvSize( h_bins * scale, s_bins * scale ),
				8,
				3
				);
			cvZero( hist_img[i] );

			// Populate our visualization with little gray squares.
			//
			float max_value = 0;
			float *fp, fval;
			cvGetMinMaxHistValue( hist[i], 0, &max_value, 0, 0 );

			for( int h = 0; h < h_bins; h++ ) {
				for ( int s = 0; s < s_bins; s++ ) {
					float bin_val = cvQueryHistValue_2D( hist[i], h, s );
					int intensity =cvRound( bin_val * 255 / max_value );
					cvRectangle(
						hist_img[i],
						cvPoint( h*scale, s*scale ),
						cvPoint( (h+1)*scale - 1, (s+1)*scale - 1 ),
						CV_RGB(intensity, intensity, intensity),
						CV_FILLED
						);
				}
			}
		}  // For 5 images

		//DISPLAY
		cvNamedWindow( "Source0", 1 );
		cvShowImage( "Source0", src[0] );
		cvNamedWindow( "H-S Histogram0", 1 );
		cvShowImage( "H-S Histogram0", hist_img[0] );

		cvNamedWindow( "Source1", 1 );
		cvShowImage( "Source1", src[1] );
		cvNamedWindow( "H-S Histogram1", 1 );
		cvShowImage( "H-S Histogram1", hist_img[1] );

		cvNamedWindow( "Source2", 1 );
		cvShowImage( "Source2", src[2] );
		cvNamedWindow( "H-S Histogram2", 1 );
		cvShowImage( "H-S Histogram2", hist_img[2] );

		cvNamedWindow( "Source3", 1 );
		cvShowImage( "Source3", src[3] );
		cvNamedWindow( "H-S Histogram3", 1 );
		cvShowImage( "H-S Histogram3", hist_img[3] );

		cvNamedWindow( "Source4", 1 );
		cvShowImage( "Source4", src[4] );
		cvNamedWindow( "H-S Histogram4", 1 );
		cvShowImage( "H-S Histogram4", hist_img[4] );

		// Compare the histogram src0 vs 1, vs2, vs3, vs4
		printf(" Comparision  Corr  Chi   Intersect  Bhat\n");
		for (i=1; i<5; ++i) {  // For histogram
			printf("Hist[0] vs: Hist[%d]: ", i);
			for(int j = 0; j < 4; ++j ) {  // For comparision type
				printf("CmpMethod[%d]: %lf: ", j, cvCompareHist(hist[0], hist[j], j ));
			}
			printf("\n");
		}
		// Oi Vey, parse histogram to earth movers signatures
		// CvRNG rgn_state = cvRNG(0xffffffff);   // Testd random bins
		CvMat* sig[5];
		int numrows = h_bins*s_bins;
		int numcols = 3;  // value,i,j
		for(i = 0; i < 5; ++i ) {
			sig[i] = cvCreateMat( numrows, 3, CV_32FC1 );
			// fill it
			float sum = 0.0;
			for ( int h = 0; h < h_bins; h++ ) {
				for ( int s = 0; s < s_bins; s++ ) {
					float bin_val = cvQueryHistValue_2D( hist[i], h, s );
					cvSet2D(sig[i], h*s_bins + s, 0, cvScalar(bin_val, bin_val, bin_val));  // Point weight
					cvSet2D(sig[i], h*s_bins + s, 1, cvScalar(h));  // Coord 1
					cvSet2D(sig[i], h*s_bins + s, 2, cvScalar(s));  // Coord 2
				}
			}
		}

		// DO EMD AND REPORT
		printf("EMD: \n");
		for( i = 1; i < 5; ++i ) {
			float emd = cvCalcEMD2( sig[0], sig[i], CV_DIST_L2 );
			printf("%f: \n", emd);
		}
		printf("\n");

		cvWaitKey(0);
	}
	else {
		printf("Error: Wront number of arguments\n");
		help();
	}
}