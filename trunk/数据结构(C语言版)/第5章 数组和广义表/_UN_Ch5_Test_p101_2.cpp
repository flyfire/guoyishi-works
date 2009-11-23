/////////////////////////////////
// Date:        2009-11-12
// Author:      Yishi Guo
// Page:        101p
// Algorithms:  5.3
/////////////////////////////////
#include <iostream>
using namespace std;

#define MAXSIZE 100

typedef struct {
	int i, j;
	int e;
} Triple;

typedef struct {
	Triple data[MAXSIZE];
	int rpos[MAXSIZE];
	int rows, cols, n;
} RLSMatrix;

void displayMatrix( RLSMatrix M ) {
	int i = 0, j = 0;
	int count = 0;
	for ( i = 0; i < M.rows; ++i ) {
		for ( j = 0; j < M.cols; ++j ) {
			if ( M.data[count].i == i &&
				M.data[count].j == j ) {
				cout << M.data[count].e;
				++count;
			} else {
				cout << 0;
			}
			cout << ' ';
		}
		cout << endl;
	}
}

int main() {
	RLSMatrix M, N, Q;
	cout << "Enter M's 'rows' 'cols' 'numbers': " << endl;
	cin >> M.rows >> M.cols >> M.n;

	cout << "Enter (i, j, e): " << endl;
	int i;
	for ( i = 0; i < M.n; ++i ) {
		cin >> M.data[i].i
			>> M.data[i].j
			>> M.data[i].e;
	}

	cout << "Enter N's 'rows' 'cols' 'numbers': " << endl;
	cin >> N.rows >> N.cols >> N.n;

	cout << "Enter (i, j, e): " << endl;
	for ( i = 0; i < N.n; ++i ) {
		cin >> N.data[i].i
			>> N.data[i].j
			>> N.data[i].e;
	}

	displayMatrix( M );
	displayMatrix( N );

	if ( M.cols != N.rows ) {
		cout << "Could not mulitply!" << endl;
		return -1;
	}

	//////////////////////////////////////////////////////////////
	// MultSMatrix( RLSMatrix M, RLSMatrix N, RLSMatrix &Q );
	//////////////////////////////////////////////////////////////

	return 0;
}