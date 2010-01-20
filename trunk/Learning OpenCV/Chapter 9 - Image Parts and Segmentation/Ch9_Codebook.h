//////////////////////////////////
// Date: 2010-01-19
// Coder: Yishi Guo
// Copy From: F:\CODE\LearningOpenCV_code\cv_yuv_codebook.h
//////////////////////////////////

// Accumulate average and ~std deviation
#ifndef CVYUV_CB
#define CVYUV_CB

#include <cv.h>  // define all of the opencv classes etc.
#include <highgui.h>
#include <cxcore.h>

#define CHANNELS 3

typedef struct ce {
	uchar learnHigh[CHANNELS]; // High side threshold for learning
	uchar learnLow[CHANNELS];  // Low side threshold for learning
	uchar max[CHANNELS];       // High side of box boundary
	uchar min[CHANNELS];       // Low side of box boundary
	int t_last_update;         // This is book keeping to allow us to kill stale entries
	int stale;                 // max negative run( biggest period of inactvity)
} code_element;

typedef struct code_book {
	code_element **cb;
	int numEntries;
	int t;   // count every access
} codeBook;

///////////////////////
// Updates the codebook entry with a new data point
//
int update_codeBook( uchar *p, codeBook &c, unsigned *cbBounds, int numChannels = 3 );


///////////////////////
// Given a pixel and a code book, determine if the pixel is covered by the codebook
//
uchar background_diff( uchar *p, codeBook &c, int numChannels, int *minMod, int* maxMod );


///////////////////////
// After you've learned for some period of time. periodically call this to clear out stale codebook entries
//
int clear_stale_entries( codeBook &c );

///////////////////////
// Count how many pixels are detected as foreground
//
int count_segementation( codeBook *c, IplImage *I, int numChannels, int *minMod, int *maxMod );

///////////////////////
// This cleans up the foreground segemetation mask derived from calls to background_diff
//
void connected_components( IplImage *mask, int poly1_hull0 = 1, float perimScale = 4.0, int *num = NULL, CvRect *bbs = NULL, CvPoint *centers = NULL );

#endif