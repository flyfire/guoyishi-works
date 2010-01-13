/////////////////////////////////////
// Date:      2009-10-21
// Modified:  2010-01-12
/////////////////////////////////////
#include "ch9_AvgBackground.h"

// GLOBALS

IplImage *IavgF, *IdiffF, *IprevF, *IhiF, *IlowF;
IplImage *Iscratch, *Iscratch2;
IplImage *Igray1, *Igray2, *Igray3;
IplImage *Imaskt;
IplImage *Ilow1, *Ilow2, *Ilow3;
IplImage *Ihi1, *Ihi2, *Ihi3;

float Icount;

void AllocateImages( IplImage *I ) {  // I is just a sample for allocation purposes

	CvSize sz = cvGetSize( I );

	IavgF = cvCreateImage( sz, IPL_DEPTH_32F, 3 );
	IdiffF = cvCreateImage( sz, IPL_DEPTH_32F, 3 );
	IprevF = cvCreateImage( sz, IPL_DEPTH_32F, 3 );
	IhiF = cvCreateImage( sz, IPL_DEPTH_32F, 3 );
	IlowF = cvCreateImage( sz, IPL_DEPTH_32F, 3 );
	Ilow1 = cvCreateImage( sz, IPL_DEPTH_32F, 1 );
	Ilow2 = cvCreateImage( sz, IPL_DEPTH_32F, 1 );
	Ilow3 = cvCreateImage( sz, IPL_DEPTH_32F, 1 );
	Ihi1 = cvCreateImage( sz, IPL_DEPTH_32F, 1 );
	Ihi2 = cvCreateImage( sz, IPL_DEPTH_32F, 1 );
	Ihi3 = cvCreateImage( sz, IPL_DEPTH_32F, 1 );
	
	cvZero( IavgF );
	cvZero( IdiffF );
	cvZero( IprevF );
	cvZero( IhiF );
	cvZero( IlowF );
	Icount = 0.00001f;  // Protect against divide by zero

	Iscratch = cvCreateImage( sz, IPL_DEPTH_32F, 3 );
	Iscratch2 = cvCreateImage( sz, IPL_DEPTH_32F, 3 );
	Igray1 = cvCreateImage( sz, IPL_DEPTH_32F, 1 );
	Igray2 = cvCreateImage( sz, IPL_DEPTH_32F, 1 );
	Igray3 = cvCreateImage( sz, IPL_DEPTH_32F, 1 );
	Imaskt = cvCreateImage( sz, IPL_DEPTH_8U, 1 );

	cvZero(Iscratch);
	cvZero(Iscratch2);
}

void DeallocateImages() {
	cvReleaseImage( &IavgF );
	cvReleaseImage( &IdiffF );
	cvReleaseImage( &IprevF );
	cvReleaseImage( &IhiF );
	cvReleaseImage( &IlowF );
	cvReleaseImage( &Ilow1 );
	cvReleaseImage( &Ilow2 );
	cvReleaseImage( &Ilow3 );
	cvReleaseImage( &Ihi1 );
	cvReleaseImage( &Ihi2 );
	cvReleaseImage( &Ihi3 );

	cvReleaseImage( &Iscratch );
	cvReleaseImage( &Iscratch2 );

	cvReleaseImage( &Igray1 );
	cvReleaseImage( &Igray2 );
	cvReleaseImage( &Igray3 );

	cvReleaseImage( &Imaskt );
}

void accumulateBackground( IplImage *I ) {
	static int first = 1;
	cvCvtScale( I, Iscratch, 1, 0 );  // To float
	if ( !first ) {
		cvAcc( Iscratch, IavgF );
		cvAbsDiff( Iscratch, IprevF, Iscratch2 );
		cvAcc( Iscratch2, IdiffF );
		Icount += 1.0;
	}
	first = 0;
	cvCopy( Iscratch, IprevF );
}

// Scale the average difference from the average image high acceptance threshold
void scaleHigh( float scale ) {
	cvConvertScale( IdiffF, Iscratch, scale );  // Converts with rounding and saturation
	cvAdd( Iscratch, IavgF, IhiF );
	cvSplit( IhiF, Ihi1, Ihi2, Ihi3, 0 );
}

// Scale the average difference from the average image low acceptance threshold
void scaleLow( float scale) {
	cvConvertScale( IdiffF, Iscratch, scale );  // Converts with rounding and saturation
	cvSub( IavgF, Iscratch, IlowF );
	cvSplit( IlowF, Ilow1, Ilow2, Ilow3, 0 );
}

// Once you've learned the background long enough, turn it into a background model
void createModelsfromStats() {
	cvConvertScale( IavgF, IavgF, (double)(1.0/Icount) );
	cvConvertScale( IdiffF, IdiffF, (double)(1.0/Icount) );
	cvAddS( IdiffF, cvScalar(1.0, 1.0, 1.0), IdiffF );  // Make sure diff is always something
	scaleHigh( HIGH_SCALE_NUM );
	scaleLow( LOW_SCALE_NUM );
}

// Create a binary:0,255 mask where 255 means forground pixel
// I       Input image, 3 channel, 8u
// Imask   mask image to be created, 1 channel 8u
// num     camera number.
//
void backgroundDiff( IplImage *I, IplImage *Imask ) { // Mask should be grayscale
	cvCvtScale( I, Iscratch, 1, 0);  // To float;
	cvSplit( Iscratch, Igray1, Igray2, Igray3, 0 );

	// Channel 1
	cvInRange( Igray1, Ilow1, Ihi1, Imask);

	// Channel 2
	cvInRange( Igray2, Ilow2, Ihi2, Imaskt );
	cvOr( Imask, Imaskt, Imask );

	// Channel 3
	cvInRange( Igray3, Ilow3, Ihi3, Imaskt );
	cvOr( Imask, Imaskt, Imask );
	
	// Finally, invert the results.
	cvSubRS( Imask, cvScalar(255), Imask );
}

/////////////////////////////////////////////
// Add Date:   2010-01-12
// Coder:      Yishi Guo
// Copy From:  http://dasl.mem.drexel.edu/~noahKuntz/openCVTut8.html
/////////////////////////////////////////////
int main( int argc, char** argv ) {
	cvNamedWindow( "Background Averaging", CV_WINDOW_AUTOSIZE );
	cvNamedWindow( "Show the mask", CV_WINDOW_AUTOSIZE );
	CvCapture *capture;
	if ( argc > 1 ) {
		capture = cvCreateFileCapture( argv[1] );
	} else {
		capture = cvCreateCameraCapture( 0 );
	}
	IplImage *frame, *mask1, *mask3;

	int frameCount = 0;
	while ( 1 ) {
		frameCount++;
		frame = cvQueryFrame( capture );
		if ( !frame ) break;
		CvSize sz = cvGetSize( frame );
		mask1 = cvCreateImage( sz, IPL_DEPTH_8U, 1 );
		mask3 = cvCreateImage( sz, IPL_DEPTH_8U, 3 );

		if ( frameCount == 1 ) {
			AllocateImages( frame );
		}

		if ( frameCount < 30 ) {
			accumulateBackground( frame );
		} else if ( frameCount == 30 ) {
			createModelsfromStats();
		} else {
			backgroundDiff( frame, mask1 );
			cvCvtColor( mask1, mask3, CV_GRAY2BGR );
			
			// For debug
			cvShowImage( "Show the mask", mask3 );

			cvNorm( mask3, mask3, CV_C, 0 );
			cvThreshold( mask3, mask3, 100, 1, CV_THRESH_BINARY );
			cvMul( frame, mask3, frame, 1.0 );
			cvShowImage( "Background Averaging", frame );

		}

		char c = cvWaitKey( 33 );
		if ( c == 27 ) break;
	}

	cvReleaseCapture( &capture );
	cvDestroyWindow( "Background Averaging" );
	cvDestroyWindow( "Show the mask" );
	DeallocateImages();
}