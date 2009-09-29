//////////////////////////////////////
// Date:         2009-09-21
// Author:       Yishi Guo
// Chapter:      2.3.2
// Page:         24/25
// Exercise:     Tests and Loops
//////////////////////////////////////
#include <iostream.h>

bool accept()
{
	cout << "Do you want to proceed (y or n)?\n";

	char answer = 0;
	cin >> answer;

	if (answer == 'y') return true;
	return false;
}

bool accept2()
{
	cout << "Do you want to proceed (y or n)?\n";

	char answer = 0;
	cin >> answer;

	switch (answer) {
	case 'y':
		return true;
	case 'n':
		return false;
	default:
		cout << "I'll take that for a no.\n";
		return false;
	}
}

bool accept3()
{
	int tries = 1;
	while (tries < 4) {
		cout << "Do you want to proceed (y or n)?\n";
		char answer = 0;
		cin >> answer;

		switch (answer) {
		case 'y':
			return true;
		case 'n':
			return false;
		default:
			cout << "Sorry, I don't understand that.\n";
			tries = tries + 1;
		}
	}
	cout << "I'll take that for a no.\n";
	return false;
}

int main()
{
	if (accept()) {
		cout << "Yes!\n";
	} else {
		cout << "No!\n";
	}

	if (accept2()) {
		cout << "Yes!\n";
	} else {
		cout << "No!\n";
	}

	if (accept3()) {
		cout << "Yes!\n";
	} else {
		cout << "No!\n";
	}

	return 0;
}