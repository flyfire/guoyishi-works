#include <iostream>
#include <string>
#include "20090528-number-to-Rome.h"

using namespace std;

int main()
{
	int number;
	cout << "Enter a number: ";
	cin >> number;

	IntToRome toRo;
	string rome = toRo.toRome(number);
	cout << "Rome: " << rome << endl;

	return 0;
}