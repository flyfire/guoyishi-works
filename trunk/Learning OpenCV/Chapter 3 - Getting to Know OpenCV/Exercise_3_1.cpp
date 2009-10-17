////////////////////////////////////////////////////////////////////
// Date:      2009-10-15
// Author:    Yishi Guo
// Exercise:  3.1
// Page:      87
// Content:   cvCeil, cvFloor, cvRound
////////////////////////////////////////////////////////////////////
#include <cv.h>
#include <highgui.h>
#include <cxcore.h>
#include <iostream.h>
#define RANDOM_COUNT 100

int main( int argc, char** argv ) {

	// Part-A:
	//
	float num;
	cout << "Enter a float number:";
	cin >> num;

	int a_absolute = CV_IABS( num );
	int a_round = cvRound( num );
	int a_ceiling = cvCeil( num );
	int a_floor = cvFloor( num );

	cout << num << ":" << endl
		 << "Absolute: " << a_absolute << endl
		 << "Round: " << a_round << endl
		 << "Ceiling: " << a_ceiling << endl
		 << "Floor: " << a_floor << endl;

	// Part-B:
	//
	CvRNG rng = cvRNG(-1);
	cout << "Random number:" << endl;
	for ( int i = 0; i < RANDOM_COUNT; ++i ) {
		cout << cvRandInt( &rng ) % RANDOM_COUNT << " ";
		if( (i+1) % 10 == 0 ) {
			cout << endl;
		}
	}

	// Part-C&D:
	//
	CvPoint2D32f point_f = cvPoint2D32f( 12.34, 56.78 );
	CvPoint point_i = cvPointFrom32f( point_f );
	CvPoint2D32f point_i_f = cvPointTo32f( point_i );

	cout << "CvPoint2D32f: x(" << point_f.x << ")"
		 << "y(" << point_f.y << ")" << endl;

	cout << "CvPoint: x(" << point_i.x << ")"
		 << "y(" << point_i.y << ")" << endl;
	
	cout << "CvPoint2D32f: x(" << point_i_f.x << ")"
		 << "y(" << point_i_f.y << ")" << endl;

	return 0;
}