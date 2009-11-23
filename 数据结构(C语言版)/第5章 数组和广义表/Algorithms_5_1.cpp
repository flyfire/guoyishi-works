////////////////////////////////////////////
// Date:          2009-11-11
// Author:        Yishi Guo
// Page:          99p
// Algorithms:    5.1
// Chapter:       4
////////////////////////////////////////////
#include <iostream>
using namespace std;

#define MAXSIZE 200
int count_times = 0;

typedef struct {
	int i, j;
	int e;
} Triple;

typedef struct {
	Triple data[MAXSIZE+1];
	int mu, nu, tu;
} TSMatrix;

// Display the results
void display_matrix( TSMatrix M ) {
	cout << "Cols: " << M.mu
		 << " Rows: " << M.nu
		 << " Numbers: " << M.tu
		 << endl;

	int row = 0, col = 0;
	int i = 1;
	int number = 0;

	for ( row = 1; row <= M.mu; ++row ) {
		for ( col = 1; col <= M.nu; ++col ) {
			if ( row == M.data[i].i &&
				col == M.data[i].j ) {
				cout << M.data[i++].e;
			} else {
				cout << 0;
			}
			cout << '\t';
		}
		cout << endl;
	}
	cout << endl;
}

// Algorithms 5.1
void TransposeSMatrix( TSMatrix M, TSMatrix &T ) {
	T.mu = M.nu;  T.nu = M.mu;  T.tu = M.tu;
	int cols = M.nu;
	int col = 1;

	int numbers = M.tu;
	int number = 1;

	int q = 1;

	for ( col = 1; col <= cols; ++col ) {
		for ( number = 1; number <= numbers; ++number ) {
			if ( M.data[number].j == col ) {
				T.data[q].i = M.data[number].j;
				T.data[q].j = M.data[number].i;
				T.data[q].e = M.data[number].e;
				++q;
			}

			// For times
			++count_times;
		}
	}
}

int main() {
	TSMatrix M, T;
	cout << "Enter rows, cols & numbers: " << endl;
	cin >> M.mu >> M.nu >> M.tu;

	cout << "Enter 'row' 'col' 'number': " << endl;

	int col, row, number;
	int count = 0;
	while ( count++ < M.tu ) {
		cin >> col >> row >> number;
		if ( !col || !row ) {
			break;
		}

		M.data[count].i = col;
		M.data[count].j = row;
		M.data[count].e = number;
	}

	display_matrix( M );

	TransposeSMatrix( M, T );

	display_matrix( T );

	// For count times
	cout << "\tTimes: " << count_times << endl;   // Cols * Numbers

	return 0;
}