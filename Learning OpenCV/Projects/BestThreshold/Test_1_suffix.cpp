///////////////
// Date:20091025
// Author: Yishi Guo
// Test for :suffix 
//////////////////
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream.h>

int main( int argc, char** argv ) {
	int i = 0;
	for( i = 0; i < argc; ++i ) {
		int len = (int)strlen( argv[i] );
		cout << "argv[" << i << "]: " << argv[i] << endl;
		cout << "Len: " << len << endl;
		char* last_four_chars = argv[i] + (len - 4);
		cout << "Last 4 char: " << last_four_chars << endl;
	}

	return 0;
}