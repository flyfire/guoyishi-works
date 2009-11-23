///////////////////////////////////////
// Date:     2009-11-12
// Author:   Yishi Guo
// Page:     101p
// Chapter:  5
///////////////////////////////////////
#include <iostream>
using namespace std;

int count_times = 0;

void clear_matrix( int** M, int m, int n ) {
	int i, j;
	for ( i = 0; i < m; ++i ) {
		for ( j = 0; j < n; ++j ) {
			M[i][j] = 0;
		}
	}
}

void display_matrix( int** M, int m, int n ) {
	int i, j;
	for ( i = 0; i < m; ++i ) {
		for ( j = 0; j < n; ++j ) {
			cout << M[i][j] << '\t';
		}
		cout << endl;
	}
	cout << endl;
}

void get_M( int** M, int m, int n ) {
	M[0][0] = 3;
	M[0][3] = 5;
	M[1][1] = -1;
	M[2][0] = 2;
}

void get_N( int** N, int m, int n ) {
	N[0][1] = 2;
	N[1][0] = 1;
	N[2][0] = -2;
	N[2][1] = 4;
}

int main() {
	int m1, n1, m2, n2;
	cout << "Enter m1, n1: " << endl;
	cin >> m1 >> n1;

	m2 = n1;

	cout << "Enter n2: " << endl;
	cin >> n2;

	int i, j;

	int** M;
	M = new int*[m1];
	for ( i = 0; i < m1; ++i ) M[i] = new int[n1];
	clear_matrix( M, m1, n1 );
	get_M( M, m1, n1 );
	display_matrix( M, m1, n1 );

	int** N;
	N = new int*[m2];
	for ( i = 0; i < m2; ++i ) N[i] = new int[n2];
	clear_matrix( N, m2, n2 );
	get_N( N, m2, n2 );
	display_matrix( N, m2, n2 );

	////////////////////////////////
	int m3 = m1, n3 = n2;
	int** Q;
	Q = new int*[m3];
	for ( i = 0; i < m3; ++i ) Q[i] = new int[n3];
	clear_matrix( Q, m3, n3);

	for ( i = 0; i < m3; ++i ) {
		for ( j = 0; j < n3; ++j ) {
			for ( int k = 0; k < n1; ++k ) {
				Q[i][j] += M[i][k] * N[k][j];

				++count_times;
			}
		}
	}

	display_matrix( Q, m3, n3 );

	cout << "Times: " << count_times << endl;  // m1*n2*n1

	return 0;
}