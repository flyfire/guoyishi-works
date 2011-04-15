//#include <cv.h>
//#include <cxcore.h>
//#include <highgui.h>
//
//int main( int argc, char** argv ) {
//	IplImage *img = cvLoadImage( "photo.jpg" );
//	if ( !img ) {
//		printf( "Error: Couldn't open the image file.\n" );
//		return 1;
//	}
//
//	cvNamedWindow( "Image: ", CV_WINDOW_AUTOSIZE );
//	cvShowImage( "Image: ", img );
//
//	cvWaitKey( 0 );
//
//	cvDestroyWindow( "Image: " );
//	cvReleaseImage( &img );
//
//	return 0;
//}

////////////////////////////////////////////////
// Date:    2011-04-15
// Coder:   Yishi Guo
// About:   Chapter 11 - Camera Models and Calibration
//          Example 11-1
////////////////////////////////////////////////
#include <cv.h>
#include <highgui.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>	// get the system time
#include <string>

int n_boards = 0;
const int board_dt = 20;
int board_w;
int board_h;

string filename;

char* intrinsics_file_name;
char* distortion_file_name;

string getFileName( bool flag = false ) {
	static int index = 0;
	static int index2 = 0;
	time_t rawtime;
	struct tm * timeinfo;
	char buffer[80];

	time( &rawtime );
	timeinfo = localtime( &rawtime );

	printf( "1" );

	strftime( buffer, 80, "%Y-%m-%d-%M-%S", timeinfo);

	printf( "2" );
	if ( flag ) {
		filename = "Un-";
		filename += string(buffer) + "-";
		sprintf( buffer, "%d", index2++ );
		filename += string(buffer) + ".jpg";
	} else {
		filename = "";
		filename += string(buffer) + "-";
		sprintf( buffer, "%d", index++ );
		filename += string(buffer) + ".jpg";
	}

	printf( "%s\n", filename.c_str() );

	return filename;
}

int main( int argc, char** argv ) {
	if ( argc < 4 ) {
		printf( "ERROR: Wrong number of input parameters\n" );
		return -1;
	}
	if ( argc > 4 ) {
		intrinsics_file_name = argv[4];
	} else {
		intrinsics_file_name = "Intrinsics.xml";
	}
	if ( argc > 5 ) {
		distortion_file_name = argv[5];
	} else {
		distortion_file_name = "Distortion.xml";
	}

	board_w = atoi( argv[1] );
	board_h = atoi( argv[2] );
	n_boards = atoi( argv[3] );
	int board_n = board_w * board_h;
	CvSize board_sz = cvSize( board_w, board_h );
	CvCapture* capture = cvCreateCameraCapture( 0 );
	assert( capture );

	cvNamedWindow( "Calibration" );
	CvMat* image_points			= cvCreateMat( n_boards * board_n, 2, CV_32FC1 );
	CvMat* object_points		= cvCreateMat( n_boards * board_n, 3, CV_32FC1 );
	CvMat* point_counts			= cvCreateMat( n_boards, 1, CV_32SC1 );
	CvMat* intrinsic_matrix		= cvCreateMat( 3, 3, CV_32FC1 );
	CvMat* distortion_coeffs	= cvCreateMat( 5, 1, CV_32FC1 );

	CvPoint2D32f* corners = new CvPoint2D32f[ board_n ];
	int corner_count;
	int successes = 0;
	int step, frame = 0;
	IplImage *image = cvQueryFrame( capture );
	IplImage *gray_image = cvCreateImage( cvGetSize(image), 8, 1 );

	while( successes < n_boards ) {
		if ( frame++ % board_dt == 0 ) {
			int found = cvFindChessboardCorners( image, board_sz, corners, &corner_count,
				CV_CALIB_CB_ADAPTIVE_THRESH | CV_CALIB_CB_FILTER_QUADS );
			cvCvtColor( image, gray_image, CV_RGB2GRAY );
			cvFindCornerSubPix( gray_image, corners, corner_count,
				cvSize(11,11), cvSize(-1, -1), cvTermCriteria(
				CV_TERMCRIT_EPS+CV_TERMCRIT_ITER, 30, 0.1));

			cvDrawChessboardCorners( image, board_sz, corners,
				corner_count, found );
			cvShowImage( "Calibration", image );

			if ( corner_count == board_n ) {
				step = successes * board_n;
				for ( int i = step, j = 0; j < board_n; ++i, ++j ) {
					CV_MAT_ELEM(*image_points, float, i, 0 ) = corners[j].x;
					CV_MAT_ELEM(*image_points, float, i, 1 ) = corners[j].y;
					CV_MAT_ELEM(*object_points, float, i, 0 ) = 1.0f * j / board_w;	// conversion from 'int' to 'float'
					CV_MAT_ELEM(*object_points, float, i, 1 ) = 1.0f * (j % board_w);
					CV_MAT_ELEM(*object_points, float, i, 2 ) = 0.0f;
				}
				CV_MAT_ELEM( *point_counts, int, successes, 0 ) = board_n;
				successes++;
				printf( " successes: %d\n", successes );	// DEBUG

				// Save the file for debug
				cvSaveImage( getFileName().c_str(), image );
			}
		}

		int c = cvWaitKey( 15 );
		if ( c == 'p' ) {
			c = 0;
			while ( c != 'p' && c != 27 ) {
				c = cvWaitKey( 250 );
			}
		}
		if ( c == 27 ) {
			return 0;
		}

		image = cvQueryFrame( capture );
	}	// END COLLECTION WHILE LOOP.

	CvMat* object_points2 = cvCreateMat( successes * board_n, 3, CV_32FC1 );
	CvMat* image_points2 = cvCreateMat( successes * board_n, 2, CV_32FC1 );
	CvMat* point_counts2 = cvCreateMat( successes, 1, CV_32SC1 );

	for ( int i = 0; i < successes * board_n; ++i ) {
		CV_MAT_ELEM( *image_points2, float, i, 0 ) =
			CV_MAT_ELEM( *image_points, float, i, 0 );
		CV_MAT_ELEM( *image_points2, float, i, 1 ) = 
			CV_MAT_ELEM( *image_points, float, i, 1 );
		CV_MAT_ELEM( *object_points2, float, i, 0 ) = 
			CV_MAT_ELEM( *object_points, float, i, 0 );
		CV_MAT_ELEM( *object_points2, float, i, 1 ) =
			CV_MAT_ELEM( *object_points, float, i, 1 );
		CV_MAT_ELEM( *object_points2, float, i, 2 ) =
			CV_MAT_ELEM( *object_points, float, i, 2 );
	}
	for ( int i = 0; i < successes; ++i ) {
		CV_MAT_ELEM( *point_counts2, int, i, 0 ) = 
			CV_MAT_ELEM( *point_counts, int, i, 0 );
	}
	cvReleaseMat( &object_points );
	cvReleaseMat( &image_points );
	cvReleaseMat( &point_counts );

	CV_MAT_ELEM( *intrinsic_matrix, float, 0, 0 ) = 1.0f;
	CV_MAT_ELEM( *intrinsic_matrix, float, 1, 1 ) = 1.0f;

	cvCalibrateCamera2(
		object_points2, image_points2,
		point_counts2, cvGetSize( image ),
		intrinsic_matrix, distortion_coeffs,
		NULL, NULL, 0 );

	cvSave( "Intrinsics.xml", intrinsic_matrix );
	cvSave( "Distortion.xml", distortion_coeffs );

	CvMat* intrinsic = (CvMat*)cvLoad( intrinsics_file_name );
	CvMat* distortion = (CvMat*)cvLoad( distortion_file_name );

	IplImage* mapx = cvCreateImage( cvGetSize(image), IPL_DEPTH_32F, 1 );
	IplImage* mapy = cvCreateImage( cvGetSize(image), IPL_DEPTH_32F, 1 );
	cvInitUndistortMap(
		intrinsic,
		distortion,
		mapx,
		mapy
	);

	cvNamedWindow( "Undistort" );
	while( image ) {
		IplImage *t = cvCloneImage( image );
		cvShowImage( "Calibration", image );
		cvSaveImage( getFileName().c_str(), image );
		cvRemap( t, image, mapx, mapy );
		cvReleaseImage( &t );
		cvShowImage( "Undistort", image );

		cvSaveImage( getFileName( true ).c_str(), image );

		int c = cvWaitKey( 1000 );
		if ( c == 'p' ) {
			c = 0;
			while ( c != 'p' && c != 27 ) {
				c = cvWaitKey( 250 );
			}
		}
		if ( c == 27 ) {
			break;
		}
		
		image = cvQueryFrame( capture );
	}

	return 0;
}
