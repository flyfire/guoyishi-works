/////////////////////////////////
// Yishi Guo                   //
// 20090910                    //
/////////////////////////////////
#include <stdio.h>
#include "cv.h"
#include "highgui.h"

float sum( const CvMat* mat ) {
	float s = 0.0f;
	for (int row = 0; row < mat->rows; row++ ) {
		const float* ptr = (const float*)(mat->data.ptr + row * mat->step);
		for ( int col = 0; col < mat->cols; col++ ) {
			s += *ptr++;
		}
	}
	return( s );
}

int main(int argc, char** argv) {
	CvMat *mat = cvCreateMat(5, 5, CV_32FC1);
	float element_3_2 = 7.7f;
	*((float*)CV_MAT_ELEM_PTR( *mat, 3, 2) ) = element_3_2;
	cvmSet(mat, 4, 4, 0.5000);
	cvSetReal2D(mat, 3, 3, 0.5000);
	float s = sum(mat);
	printf("%f\n", s);
	return 0;
}