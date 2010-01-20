//////////////////////////////////
// Date: 2010-01-19
// Coder: Yishi Guo
// Copy From: F:\CODE\LearningOpenCV_code\cv_yuv_codebook.cpp
//////////////////////////////////
#include "Ch9_Codebook.h"

// For connected components:
// Approx.threshold - the bigger it is, the simpler is the boundary
//
#define CVCONTOUR_APPROX_LEVEL 2

// How many iterations of erosion and/or dilation there should be
//
#define CVCLOSE_ITR 1

// Just some convienience macros
#define CVX_WHITE CV_RGB( 0xff, 0xff, 0xff )
#define CVX_BLACK CV_RGB( 0x00, 0x00, 0x00 )


// Update codebook
////////////////////////
//
// Learning the background
// 
// int update_codebook( uchar *p, codeBook &c, unsigned cbBounds)
//
int update_codebook(
  uchar *p,
  codeBook &c,
  unsigned *cbBounds,
  int numChannels
  ) {
	int n;
	unsigned int high[3], low[3];
	for ( n = 0; n < numChannels; n++ ) {
		high[n] = *(p+n) + *(cbBounds + n);
		if ( high[n] > 255 ) high[n] = 255;
		low[n] = *(p+n) - *(cbBounds + n);
		if ( low[n] < 0 ) low[n] = 0;
	}
	int matchChannel;

	// SEE IF THIS FITS AN EXISTING CODEWORD
	//
	for ( int i = 0; i < c.numEntries; i++ ) {
		matchChannel = 0;
		for ( n = 0; n < numChannels; n++ ) {
			if ( ( c.cb[i]->learnLow[n] <= *(p+n) ) &&
				// Found an extry for this channel
				(*(p+n) <= c.cb[i]->learnHigh[n]) ) {
				matchChannel++;
			}
		}
		if ( matchChannel == numChannels ) {  // If an entry was found
			c.cb[i]->t_last_update = c.t;
			// adjust this codeword for the first channel
			for ( n = 0; n < numChannels; n++ ) {
				if ( c.cb[i]->max[n] < *(p+n) ) {
					c.cb[i]->max[n] = *(p+n);
				} else if ( c.cb[i]->min[n] > *(p+n) ) {
					c.cb[i]->min[n] = *(p+n);
				}
			}
			break;
		}
	}

	// OVERHEAD TO TRACK POTENTIAL STALE ENTRIES
	//
	for ( int s = 0; s < c.numEntries; s++ ) {
		// Track which codebook entries are going stale:
		//
		int negRun = c.t - c.cb[s]->t_last_update;
		if ( c.cb[s]->stale < negRun ) c.cb[s]->stale = negRun;
	}

	// ENTER A NEW CODEWORD IF NEEDED
	//
	if ( i == c.numEntries ) { // if no existing codeword found, make one
		code_element **foo = new code_element*[c.numEntries+1];
		for ( int ii = 0; ii < c.numEntries; ii++ ) {
			foo[ii] = c.cb[ii];
		}
		foo[c.numEntries] = new code_element;
		if ( c.numEntries ) delete [] c.cb;
		c.cb = foo;
		for ( n = 0; n < numChannels; n++ ) {
			c.cb[c.numEntries]->learnHigh[n] = high[n];
			c.cb[c.numEntries]->learnLow[n] = low[n];
			c.cb[c.numEntries]->max[n] = *(p+n);
			c.cb[c.numEntries]->min[n] = *(p+n);
		}
		c.cb[c.numEntries]->t_last_update = c.t;
		c.cb[c.numEntries]->stale = 0;
		c.numEntries += 1;
	}

	// SLOWLY ADJUST LEARNING BOUNDS
	//
	for ( n = 0; n < numChannels; n++ ) {
		if ( c.cb[i]->learnHigh[n] < high[n] ) c.cb[i]->learnHigh[n] += 1;
		if ( c.cb[i]->learnLow[n] < low[n] ) c.cb[i]->learnLow[n] -= 1;
	}
	return ( i );
}

///////////////////////
//
// Learning with moving foreground objects
//
// int clear_stale_entries(codeBook &c)
//
int clear_stale_entries( codeBook &c ) {
	int staleThresh = c.t >> 1;
	int *keep = new int [c.numEntries];
	int keepCnt = 0;
	// SEE WHICH CODEBOOK ENTRIES ARE TOO STALE
	//
	for ( int i = 0; i < c.numEntries; i++ ) {
		if ( c.cb[i]->stale > staleThresh ) {
			keep[i] = 0;  // Mark for destruction
		} else {
			keep[i] = 1;
			keepCnt += 1;
		}
	}
	// KEEP ONLY THE GOOD
	//
	c.t = 0;  // Full reset on stale tracking
	code_element **foo = new code_element*[keepCnt];
	int k = 0;
	for ( int ii = 0; ii < c.numEntries; ii++ ) {
		if ( keep[ii] ) {
			foo[k] = c.cb[ii];
			// We have to refresh these entries for next clearStale
			foo[k]->t_last_update = 0;
			k++;
		}
	}

	// CLEAN UP
	//
	delete [] keep;
	delete [] c.cb;
	c.cb = foo;
	int numCleared = c.numEntries - keepCnt;
	c.numEntries = keepCnt;
	return( numCleared );
}

////////////////////////////
//
// Background differencing: Finding foreground objects
//
// uchar background_diff( uchar *p, codeBook &c,
//                        int minMod, int maxMod)
//
uchar background_diff(
	uchar*    p,
	codeBook& c,
	int       numChannels,
	int*      minMod,
	int*      maxMod
) {
	int matchChannel;

	// SEE IF THIS FITS AN EXISTING CODEWORD
	//
	for ( int i = 0; i < c.numEntries; i++ ) {
		matchChannel = 0;
		for ( int n = 0; n < numChannels; n++ ) {
			if ( (c.cb[i]->min[n] - minMod[n] <= *(p+n) ) &&
				(*(p+n) < c.cb[i]->max[n] + maxMod[n]) ) {
				matchChannel++;  // Found an entry for this channel
			} else {
				break;
			}
		}
		if ( matchChannel == numChannels ) {
			break;  // Found an entry that matched all channels
		}
	}
	if ( i >= c.numEntries ) return ( 255 );
	return ( 0 );
}

// Connected Components for Foreground Cleanup
//

void find_connected_components(
	IplImage *mask,
	int poly1_hull0,
	float perimScale,
	int *num,
	CvRect *bbs,
	CvPoint *centers
) {
	static CvMemStorage* mem_storage = NULL;
	static CvSeq*        contours    = NULL;

	// CLEAN UP RAW MASK
	//
	cvMorphologyEx( mask, mask, 0, 0, CV_MOP_OPEN, CVCLOSE_ITR );
	cvMorphologyEx( mask, mask, 0, 0, CV_MOP_CLOSE, CVCLOSE_ITR );

	// FIND CONTOURS AROUND ONLY BIGGER REGIONS
	//
	if ( mem_storage == NULL ) {
		mem_storage = cvCreateMemStorage( 0 );
	} else {
		cvClearMemStorage( mem_storage );
	}

	CvContourScanner scanner = cvStartFindContours(
		mask,
		mem_storage,
		sizeof( CvContour ),
		CV_RETR_EXTERNAL,
		CV_CHAIN_APPROX_SIMPLE
	);

	CvSeq* c;
	int numCont = 0;
	while ( (c = cvFindNextContour( scanner ) ) != NULL ) {
		double len = cvContourPerimeter( c );

		// calculate perimeter len threshold:
		//
		double q = (mask->height + mask->width) / perimScale;

		// Get rid of blob if its perimeter is too small:
		//
		if ( len < q ) {
			cvSubstituteContour( scanner, NULL );
		} else {

			// Smooth its edges if its large enough
			//
			CvSeq* c_new;
			if ( poly1_hull0 ) {
				
				// Polygonal approximation
				//
				c_new = cvApproxPoly(
					c,
					sizeof( CvContour ),
					mem_storage,
					CV_POLY_APPROX_DP,
					CVCONTOUR_APPROX_LEVEL,
					0
				);
			} else {

				// Convex Hull of the segmentation
				//
				c_new = cvConvexHull2(
					c,
					mem_storage,
					CV_CLOCKWISE,
					1
				);
			}
			cvSubstituteContour( scanner, c_new );
			numCont++;
		}
	}
	contours = cvEndFindContours( &scanner );

	// PAINT THE FOUND REGIONS BACK INTO THE IMAGE
	//
	cvZero( mask );
	IplImage* maskTemp;

	// CALC CENTER OF MASS AND/OR BOUNDING RECTANGLES
	//
	if ( num != NULL ) {

		// User wants to collect statistics
		//
		int N = *num, numFilled = 0, i = 0;
		CvMoments moments;
		double M00, M01, M10;
		maskTemp = cvCloneImage( mask );
		for ( i = 0, c = contours; c != NULL; c = c->h_next, i++ ) {
			if ( i < N ) {
				
				// Only process up to *num of them
				//
				cvDrawContours(
					maskTemp,
					c,
					CVX_WHITE,
					CVX_WHITE,
					-1,
					CV_FILLED,
					8
				);

				// Find the center of each contour
				//
				if ( centers != NULL ) {
					cvMoments( maskTemp, &moments, 1 );
					M00 = cvGetSpatialMoment( &moments, 0, 0 );
					M10 = cvGetSpatialMoment( &moments, 1, 0 );
					M01 = cvGetSpatialMoment( &moments, 0, 1 );
					centers[i].x = (int)(M10/M00);
					centers[i].y = (int)(M01/M00);
				}

				// Bounding rectangles around blobs
				//
				if ( bbs != NULL ) {
					bbs[i] = cvBoundingRect( c );
				}
				cvZero( maskTemp );
				numFilled++;
			}

			// Draw filled contours into mask
			//
			cvDrawContours(
				mask,
				c,
				CVX_WHITE,
				CVX_WHITE,
				-1,
				CV_FILLED,
				8
			);
		}  // end looping over contours
		*num = numFilled;
		cvReleaseImage( &maskTemp );
	}

	// ELSE JUST DRAW PROCESSED CONTOURS INTO THE MASK
	//
	else {
		// The user doesn't want statistics, just draw the contours
		//
		for ( c = contours; c != NULL; c = c->h_next ) {
			cvDrawContours(
				mask,
				c,
				CVX_WHITE,
				CVX_WHITE,
				-1,
				CV_FILLED,
				8
			);
		}
	}
}

int main() {
	return 0;
}

