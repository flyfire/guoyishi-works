////////////////////////////////
// Date: 2010-01-19
// Coder: Yishi Guo
// Copy From: F:\CODE\LearningOpenCV_Code\ch9_backgroundAVG.cpp
////////////////////////////////

#include "cv.h"
#include "highgui.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Ch9_AvgBackground.h"
#include "Ch9_Codebook.h"

// VARIABLES for CODECOOK METHOD:
codeBook *cB; // This will be our lnear model of the image, a vector
              // of lengh = heigth* width
int maxMod[CHANNELS];  // Add these (possibly negative) number onto max
                       // level when code_element determining if new pixel if foreground
int minMod[CHANNELS];  // Subract these ( possible negative ) number from min
                       // level code_element when determining if pixel is foreground
unsigned cbBounds[CHANNELS];  // Code book bound for learning
bool ch[CHANNELS];
int nChannels = CHANNELS;
int imageLen = 0;
uchar *pColor;  // YUV pointer

void help() {
	printf( "\nLearning background and find foredground using simple average and average difference learning method:\n"
	        "\nUSAGE:\n ch9_background startFrameCollection# endFrameCollection# [movie filename, else from camera]\n"
			"if from AVI, then optionally add HighAvg, LowAvg, HighCB_Y LowCB_Y HighCB_U LowCB_U HighCB_V LowCB_V\n\n"
			"***keep the fcus on the video windows. NOT the consol***\n\n"
			"INTERACTIVE PRAMETERS:\n"
			"\tESC,q,Q - quit the program\n"
			"\th - print this help\n"
			"\tp - pause toggle\n"
			"\ts - single step\n"
			"\tr - run mode (single step off)\n"
			"=== AVG PARAMS ===\n"
			"\t-    - bump high threshold UP by 0.25\n"
			"\t=    - bump high threshold DOWN by 0.25\n"
			"\t[    - bump low threshold UP by 0.25\n"
			"\t]    - bump low threshold DOWN by 0.25\n"
			"=== CODEBOOK PARAMS ===\n"
			"\ty,u,v - only adjust channel 0(y) or 1(u) or 2(v) respectively\n"
			"\ta - adjust all 3 channels at once\n"
			"\ti,o    - bump upper threshold up, down by 1\n"
			"\tk,l    - bump lower threshold up, down by 1\n"
		);
}

//
// USAGE: ch9_background startFrameCollection# endFrameCollection# [movie filename, else from camera]
// if from AVI, then opetionally add HighAvg, LowAvg, HighCV_Y lowCV_Y HighCB_U LowCB_U HighCV_V LowCB_V
//
int main( int argc, char** argv ) {
	IplImage *rawImage = 0, *yuvImage = 0;  // yuvImage is for codebook method
	IplImage *ImaskAVG = 0, *ImaskAVGCC = 0;
	IplImage *ImaskCodeBook = 0, *ImaskCodeBookCC = 0;
	CvCapture* capture = 0;

	int startcapture = 1;
	int endcapture = 30;
	int c, n;

	maxMod[0] = 3;  // Set color thresholds to default values
	minMod[0] = 10;
	maxMod[1] = 1;
	minMod[1] = 1;
	maxMod[2] = 1;
	minMod[2] = 1;
	float scalehigh = HIGH_SCALE_NUM;
	float scalelow = LOW_SCALE_NUM;
	
	if ( argc < 3 ) {
		printf( "ERROR: To few parmeters\n" );
		help();
	} else {
		if ( argc == 3 ) {
			printf( "Capture from Camera\n" );
			capture = cvCaptureFromCAM( 0 );
		} else {
			printf( "Capture from file %s\n", argv[3] );
			capture = cvCreateFileCapture( argv[3] );
			if ( !capture ) {
				printf( "Couldn't open %s\n", argv[3] );
				return -1;
			}
		}
		if ( isdigit( argv[1][0] ) ) {  // Start from of background capture
			startcapture = atoi( argv[1] );
			printf( "startcapture = %d\n", startcapture );
		}
		if ( isdigit( argv[2][0] ) ) {  // End frame of background capture
			endcapture = atoi( argv[2] );
			printf( "endcapture = %d\n", endcapture );
		}
		if ( argc > 4 ) {  // See if parameters are set from command line
			// FOR AVG MODEL
			if ( argc >= 5 ) {
				if ( isdigit( argv[4][0] ) ) {
					scalehigh = (float)atoi( argv[4] );
				}
			}
			if ( argc >= 6 ) {
				if ( isdigit( argv[5][0] ) ) {
					scalelow = (float)atoi( argv[5] );
				}
			}
			// FOR CODEBOOK MODEL, CHANNEL 0
			if ( argc >= 7 ) {
				if ( isdigit(argv[6][0]) ) {
					maxMod[0] = atoi( argv[6] );
				}
			}
			if ( argc >= 8 ) {
				if ( isdigit( argv[7][0] ) ) {
					minMod[0] = atoi( argv[7] );
				}
			}

			// Channel 1
			if ( argc >= 9 ) {
				if ( isdigit( argv[8][0] ) ) {
					maxMod[1] = atoi( argv[8] );
				}
			}
			if ( argc >= 10 ) {
				if ( isdigit( argv[9][0] ) ) {
					minMod[1] = atoi( argv[9] );
				}
			}
			// Channel 2
			if ( argc >= 11 ) {
				if ( isdigit( argv[10][0] ) ) {
					maxMod[2] = atoi( argv[10] );
				}
			}
			if ( argc >= 12 ) {
				if ( isdigit( argv[11][0] ) ) {
					minMod[2] = atoi( argv[11] );
				}
			}
		}
	}

	// MAIN PROCESSING LOOP:
	bool pause = false;
	bool singlestep = false;

	if ( capture ) {
		cvNamedWindow( "Raw", 1 );
		cvNamedWindow( "AVG_ConnectComp", CV_WINDOW_AUTOSIZE );
		cvNamedWindow( "ForegroundCodeBook", 1 );
		cvNamedWindow( "CodeBook_ConnectComp", 1 );
		cvNamedWindow( "ForegroundAVG", 1 );

		int i = -1;

		for ( ; ; ) {
			if ( !pause ) {
				rawImage = cvQueryFrame( capture );
				++i;  // count it
				if ( !rawImage)
					break;

				// REMOVE THIS FOR GENERAL OPERATION, JUST A CONVIENIENCE WHEN RUNNING WITH THE SMALL tree.avi file
				if ( i == 56 ) {
					pause = 1;
					printf( "\n\nVideo paused for your convienience at frame 50 to work with demo\n"
						"You may adjust parameters. single step or continue running\n\n" );
					help();
				}
			}
			if ( singlestep ) {
				pause = true;
			}

			// Frist time:
			if ( 0 == i ) {
				printf( "\n . . . wait for it . . .\n" );  // Just in case you wonder why the image is white at first
				// AVG METHOD ALLOCATION
				AllocateImages( rawImage );
				scaleHigh( scalehigh );
				scaleLow( scalelow );
				ImaskAVG = cvCreateImage( cvGetSize(rawImage), IPL_DEPTH_8U, 1 );
				ImaskAVGCC = cvCreateImage( cvGetSize(rawImage), IPL_DEPTH_8U, 1 );
				cvSet( ImaskAVG, cvScalar(255) );

				// CODEBOOK METHOD ALLOCATION:
				yuvImage = cvCloneImage( rawImage );
				ImaskCodeBook = cvCreateImage( cvGetSize(rawImage), IPL_DEPTH_8U, 1 );
				ImaskCodeBookCC = cvCreateImage( cvGetSize(rawImage), IPL_DEPTH_8U, 1 );
				cvSet( ImaskCodeBook, cvScalar( 255 ) );
				imageLen = rawImage->width*rawImage->height;
				cB = new codeBook[imageLen];
				for ( int f = 0; f < imageLen; f++ ) {
					cB[f].numEntries = 0;
				}
				for ( int nc = 0; nc < nChannels; nc++ ) {
					cbBounds[nc] = 10;  // Learning bounds factor
				}
				ch[0] = true;  // Allow threshold setting simuleaneously for all channels
				ch[1] = true;
				ch[2] = true;
			}
			// If we've got an rawImage and are good to go:
			if ( rawImage ) {
				cvCvtColor( rawImage, yuvImage, CV_BGR2YCrCb );  // YUV For codebook method
				// This is where we build our background model
				if ( !pause && i >= startcapture && i < endcapture ) {
					// LEARNING THE AVERAGE AND AVG DIFF BACKGROUND
					accumulateBackground( rawImage );
					// LEARNING THE CODEBOOK BACKGROUND
					pColor = (uchar*)((yuvImage)->imageData);
					for ( int c = 0; c < imageLen; c++ ) {
						update_codeBook( pColor, cB[c], cbBounds, nChannels );
						pColor += 3;
					}
				}
				// When done, create the background model
				if ( i == endcapture ) {
					createModelsfromStats();
				}
				// Find the foreground if any
				if ( i >= endcapture ) {
					// FIND FOREGROUND BY AVG METHOD:
					backgroundDiff( rawImage, ImaskAVG );
					cvCopy( ImaskAVG, ImaskAVGCC );
					connected_components( ImaskAVGCC );
					// FIND FOREGROUND BY CODEBOOK METHOD:
					uchar maskPixelCodeBook;
					pColor = (uchar *)((yuvImage)->imageData);  // 3 channel yuv image
					uchar *pMask = (uchar *)((ImaskCodeBook)->imageData);  // 1 channel image
					for ( int c = 0; c < imageLen; c++ ) {
						maskPixelCodeBook = background_diff( pColor, cB[c], nChannels, minMod, maxMod );
						*pMask++ = maskPixelCodeBook;
						pColor += 3;
					}
					// This part just to visualize bounding boxes and centers if desired
					cvCopy( ImaskCodeBook, ImaskCodeBookCC );
					connected_components( ImaskCodeBookCC );
				}
				// Display
				cvShowImage( "Raw", rawImage );
				cvShowImage( "AVG_ConnectComp", ImaskAVGCC );
				cvShowImage( "ForegroundAVG", ImaskAVG );
				cvShowImage( "ForegroundCodeBook", ImaskCodeBook );
				cvShowImage( "CodeBook_ConnectComp", ImaskCodeBookCC );

				// USER INPUT:
				c = cvWaitKey( 10 ) & 0xFF;
				// End processing on ESC, q or Q
				if ( c == 27 || c == 'q' || c == 'Q' )
					break;
				// Else check for user input
				switch ( c ) {
					case 'h':
						help();
						break;
					case 'p':
						pause ^= 1;
						break;
					case 's':
						singlestep = 1;
						pause = false;
						break;
					case 'r':
						pause = false;
						singlestep = false;
						break;
						// AVG BACKGROUND PARAMS
					case '-':
						if ( i > endcapture ) {
							scalehigh += 0.25;
							printf( "AVG scalehigh=%f\n", scalehigh );
							scaleHigh( scalehigh );
						}
						break;
					case '=':
						if ( i > endcapture ) {
							scalehigh -= 0.25;
							printf( "AVG scalehigh=%f\n", scalehigh );
							scaleHigh( scalehigh );
						}
						break;
					case '[':
						if ( i > endcapture ) {
							scalelow += 0.25;
							printf( "AVG scalelow=%f\n", scalelow );
							scaleLow( scalelow );
						}
						break;
					case ']':
						if ( i > endcapture ) {
							scalelow -= 0.25;
							printf( "AVG scalelow=%f\n", scalelow );
							scaleLow( scalelow );
						}
						break;

						// CODEBOOK PARAMS
					case 'y':
					case '0':
						ch[0] = 1;
						ch[1] = 0;
						ch[2] = 0;
						printf( "CodeBook YUV Channels active: " );
						for ( n = 0; n < nChannels; n++ )
							printf( "%d, ", ch[n] );
						printf( "\n" );
						break;
					case 'u':
					case '1':
						ch[0] = 0;
						ch[1] = 1;
						ch[2] = 0;
						printf( "CodeBook YUV Channels active: " );
						for ( n = 0; n < nChannels; n++ )
							printf( "%d, ", ch[n] );
						printf( "\n" );
						break;
					case 'v':
					case '2':
						ch[0] = 0;
						ch[1] = 0;
						ch[2] = 1;
						printf( "CodeBook YUV Channels active: " );
						for ( n = 0; n < nChannels; n++ )
							printf( "%d, ", ch[n] );
						printf( "\n" );
						break;
					case 'a':
					case '3':
						ch[0] = 1;
						ch[1] = 1;
						ch[2] = 1;
						printf( "CodeBook YUV Channels active: " );
						for ( n = 0; n < nChannels; n++ )
							printf( "%d, ", ch[n] );
						printf( "\n" );
						break;
					case 'i':  // modify max classification bounds( max bound goes higher)
						for ( n = 0; n < nChannels; n++ ) {
							if ( ch[n] )
								maxMod[n] += 1;
							printf( "%.4d, ", maxMod[n] );
						}
						printf( " CodeBook High Side\n" );
						break;
					case 'o':  // modify max classification bounds (max bound goes lower )
						for ( n = 0; n < nChannels; n++ ) {
							if ( ch[n] )
								maxMod[n] -= 1;
							printf( "%.4d, ", maxMod[n] );
						}
						printf( " CodeBook High Side\n" );
						break;
					case 'k':  // modify min classification bounds ( min bound goes higher )
						for ( n = 0; n < nChannels; n++ ) {
							if ( ch[n] )
								minMod[n] += 1;
							printf( "%.4d, ", minMod[n] );
						}
						printf( " CodeBook Low Side\n" );
						break;
					case 'l':  // modify min classification bounds ( min bound goes lower )
						for ( n = 0; n < nChannels; n++ ) {
							if ( ch[n] )
								minMod[n] -= 1;
							printf( "%.4d, ", minMod[n] );
						}
						printf( " CodeBook Low Side\n" );
						break;
				}
			}
		}
		cvReleaseCapture( &capture );
		cvDestroyWindow( "Raw" );
		cvDestroyWindow( "ForegroundAVG" );
		cvDestroyWindow( "AVG_ConnectComp" );
		cvDestroyWindow( "ForegroundCodeBook" );
		cvDestroyWindow( "CodeBook_ConnectComp" );

		DeallocateImages();
		if ( yuvImage) cvReleaseImage( &yuvImage );
		if ( ImaskAVG ) cvReleaseImage( &ImaskAVG );
		if ( ImaskAVGCC ) cvReleaseImage( &ImaskAVGCC );
		if ( ImaskCodeBook ) cvReleaseImage( &ImaskCodeBook );
		if ( ImaskCodeBookCC ) cvReleaseImage( &ImaskCodeBookCC );
		delete [] cB;
	}
	else {
		printf( "\n\nDarn, Something wrong with the parameters\n\n" );
		help();
	}
	return 0;
}