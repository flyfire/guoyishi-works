/////////////////////////////////////////
// Date: 2009-11-12
// Author: Yishi Guo
// Chapter: 5
// Algorithm: 5.1 Fast Transpose
// Page: 100p
/////////////////////////////////////////
#include <iostream>
using namespace std;

#define MAXSIZE 12500
int count_times = 0;

typedef struct {
	int i, j;
	int e;
} Triple;
typedef struct {
	Triple data[MAXSIZE+1];
	int rows, cols, n;
} TSMatrix;

// Fast Transpose
void FastTransposeSMatrix( TSMatrix M, TSMatrix &T ) {
	T.cols = M.rows;  T.rows = M.cols;  T.n = M.n;
	int* num = new int[M.cols+1];
	int* cpot = new int[M.cols+1];

	int i = 1;
	for ( i = 0; i <= M.cols; ++i ) {  // Clear
		num[i] = 0;

		++count_times;
	}
	for ( i = 1; i <= M.n; ++i ) {     // Create num[]
		++num[M.data[i].j];

		++count_times;
	}

	for ( i = 1; i <= M.cols; ++i ) {  // Create cpot[]
		if ( i == 1 ) {
			cpot[i] = 1;
		} else {
			cpot[i] = cpot[i-1] + num[i-1];
		}

		++count_times;
	}

	for ( i = 1; i <= M.n; ++i ) {
		int pos = cpot[M.data[i].j]++;
		T.data[pos].e = M.data[i].e;
		T.data[pos].j = M.data[i].i;
		T.data[pos].i = M.data[i].j;
		
		++count_times;
	}
}

// Display matrix for debug
void display_matrix( TSMatrix M ) {
	cout << "Rows: " << M.rows
		 << " Cols: " << M.cols
		 << " Numbers: " << M.n
		 << endl;

	int count = 1;
	int row = 1, col = 1;
	for ( row = 1; row <= M.rows; ++row ) {
		for ( col = 1; col <= M.cols; ++col ) {
			if ( M.data[count].i == row &&
				M.data[count].j == col ) {
				cout << M.data[count++].e;
			} else {
				cout << '0';
			}
			cout << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

int main() {
	TSMatrix M, T;
	cout << "Enter rows, cols, numbers: ";
	cin >> M.rows >> M.cols >> M.n;

	cout << "Enter 'row' 'col' 'element': " << endl;

	int i = 0;
	int count = 1;
	while ( i++ < M.n ) {
		cin >> M.data[count].i >> M.data[count].j >> M.data[count].e;
		++count;
	}

	display_matrix( M );

	FastTransposeSMatrix( M, T );

	display_matrix( T );

	cout << "Times: " << count_times << endl;

	return 0;
}