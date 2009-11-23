/////////////////////////////////////////////
// Date:     2009-11-03
// Author:   Yishi Guo
// Project:  Select Color
/////////////////////////////////////////////
#include "cv.h"
#include "highgui.h"
#include <stdio.h>

IplImage* img;
int g_value = 0;
int r_value = 0;
int b_value = 0;

// Convert integer to hex chars
//
void int2hexchar( int value, char &char1, char &char2 ) {
	char *hex = new char[2];
	hex[0] = 'N';
	hex[1] = 'A';
	if ( value >= 0 && value <= 255 ) {
		int i = 0;
		for ( i = 0; i < 2; ++i ) {
			int number;
			if ( i == 0 ) {
				number = value / 16;
			} else if ( i == 1 ) {
				number = value;
			}

			switch( number ) {
				case 0: hex[i] = '0'; break;
				case 1: hex[i] = '1'; break;
				case 2: hex[i] = '2'; break;
				case 3: hex[i] = '3'; break;
				case 4: hex[i] = '4'; break;
				case 5: hex[i] = '5'; break;
				case 6: hex[i] = '6'; break;
				case 7: hex[i] = '7'; break;
				case 8: hex[i] = '8'; break;
				case 9: hex[i] = '9'; break;
				case 10: hex[i] = 'A'; break;
				case 11: hex[i] = 'B'; break;
				case 12: hex[i] = 'C'; break;
				case 13: hex[i] = 'D'; break;
				case 14: hex[i] = 'E'; break;
				case 15: hex[i] = 'F'; break;
			}

			value %= 16;
		}
	}
	char1 = hex[0];
	char2 = hex[1];

	delete[] hex;
	return;
}



void set_color( IplImage* img, int red, int green, int blue ) {
	CvScalar color = CV_RGB( red, green, blue );
	cvSet( img, color );

	// Put Text to Image
	//
	char *text = new char[7];
	text[6] = '\0';
	int2hexchar( red, text[0], text[1] );
	int2hexchar( green, text[2], text[3] );
	int2hexchar( blue, text[4], text[5] );

	CvScalar complementaryColor = CV_RGB( 0xff-red, 0xff-green, 0xff-blue );
	CvFont font;
	cvInitFont(
		&font,                      // font
		CV_FONT_HERSHEY_SIMPLEX,    // font face
		0.5,                        // hscale
		0.5,                        // vscale
		0,                          // shear
		1,                          // thickness
		8                           // line type
	);
	cvPutText(
		img,                        // image
		text,                       // text
		cvPoint(2, 20),             // origin
		&font,                      // font
		complementaryColor          // color
	);

	delete[] text;
}

void red_callback( int pos ) {
	set_color( img, pos, g_value, b_value );
}

void green_callback( int pos ) {
	set_color( img, r_value, pos, b_value );
}

void blue_callback( int pos ) {
	set_color( img, r_value, g_value, pos );
}

int main( int argc, char** argv ) {

	// Create and Clear Image
	//
	img = cvCreateImage( cvSize(300, 300), IPL_DEPTH_8U, 3 );
	cvZero( img );

	// Create Window and Show Image
	//
	cvNamedWindow( "Select Color", CV_WINDOW_AUTOSIZE );

	// Create the "Green", "Red", "Blue" Thrackbars
	//

	cvCreateTrackbar(
		"Red",
		"Select Color",
		&r_value,
		255,
		red_callback
	);

	cvCreateTrackbar(
		"Green",
		"Select Color",
		&g_value,
		255,
		green_callback
	);

	cvCreateTrackbar(
		"Blue",
		"Select Color",
		&b_value,
		255,
		blue_callback
	);

	// Show the Colorized Image
	set_color( img, r_value, g_value, b_value );
	while ( 1 ) {
		cvShowImage( "Select Color", img );
		if ( cvWaitKey(1) == 27 ) {
			break;
		}
	}

	cvReleaseImage( &img );
	cvDestroyWindow( "Select Color" );

	return 0;
}