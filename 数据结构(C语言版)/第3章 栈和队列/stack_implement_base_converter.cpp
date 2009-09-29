//////////////////////////////
// Date:     2009-09-25
// Author:   Yishi Guo
// Chapter:  3.2.1
// Page:     48
// Belong:   Stack Implement
//////////////////////////////
#include <iostream.h>
#include "stack_mine.cpp"

char convert( int i ) {
	switch( i ) {
	case 1:		return '1';
	case 2:		return '2';
	case 3:		return '3';
	case 4:		return '4';
	case 5:		return '5';
	case 6:		return '6';
	case 7:		return '7';
	case 8:		return '8';
	case 9:		return '9';
	case 10:		return 'a';
	case 11:		return 'b';
	case 12:		return 'c';
	case 13:		return 'd';
	case 14:		return 'e';
	case 15:		return 'f';
	}

	return '0';
}

int main() {
	StackType<char> stack_int;
	int src = 0;
	int dst = 0;
	int number = 0;
	// int count = 0;

	while ( 1 ) {
		// count = 0;
		cout << "Enter src dst number:";
		cin >> src >> dst >> number;

		while ( number ) {
			stack_int.push(convert(number%dst));
			number /= dst;
		}

		while (!stack_int.empty()) {
			cout << stack_int.top();
			stack_int.pop();
		}
		cout << endl;

		if( src == 0 ) {
			break;
		}
	}

	return 0;
}
