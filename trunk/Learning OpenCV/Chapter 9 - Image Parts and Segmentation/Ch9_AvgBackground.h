///////////////////////
// Date: 2009-10-21
///////////////////////
#ifndef AVGSEG_
#define AVGSEG_

#include "cv.h"  // define all of the opencv classes etc.
#include "highgui.h"
#include "cxcore.h"

// IMPORTANT DEFINES:
#define NUM_CAMERAS 1       // This function can handle an array of cameras
#define HIGH_SCALE_NUM 7.0  // How many average differences from average image on the high side == background
#define LOW_SCALE_NUM 6.0   // How many average differences from average image on the low side == background

void AllocateIamges( IplImage *I );
void DeallocateImages();
void accumulateBackground( IplImage *I, int number = 0 );
void scaleHigh( float scale = HIGH_SCALE_NUM, int num = 0 );
void scaleLow( float scale = LOW_SCALE_NUM, int num = 0 );
void createModelsfromStats();
void backgroundDii( IplImage *I, IplImage *Imask, int num = 0 );

#endif

