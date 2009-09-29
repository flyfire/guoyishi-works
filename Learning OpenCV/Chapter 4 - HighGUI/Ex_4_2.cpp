///////////////////////////////////////////////////////
// Example 4-2. Using a trackbar to create a "switch" 
// that the user can return on and off
// Editor: Yishi Guo
// Date: 20090913
///////////////////////////////////////////////////////

#include <cv.h>
#include <highgui.h>
#include <stdio.h>
// We make this value global so everyone can see it.
//
int g_switch_value = 0;

//
void switch_off_function() {
	printf("Pause\n");
}
void switch_on_function() {
	printf("Run\n");
}

// This will be the callback that we give to the
// trackbar.
//
void switch_callback( int position ) {
	if ( position == 0 ) {
		switch_off_function();
	} else {
		switch_on_function();
	}
}

int main( int argc, char** argv ) {
	// Named the main window
	//
	cvNamedWindow( "Demo Window", 1 );

	// Create the trackbar. We give it a name,
	// and tell it the name of the parent window.
	//
	cvCreateTrackbar(
		"Switch",
		"Demo Window",
		&g_switch_value,
		1,
		switch_callback
	);

	// This will just cause OpenCV to idle until
	// someone hits the "Escape" key.
	//
	while ( 1 ) {
		if ( cvWaitKey(15) == 27 )
			break;
	}
}
