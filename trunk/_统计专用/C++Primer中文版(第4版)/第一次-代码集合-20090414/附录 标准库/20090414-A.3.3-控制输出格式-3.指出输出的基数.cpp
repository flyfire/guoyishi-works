//20090414
#include <iostream>
using namespace std;

void printvalue()
{
	const int ival = 14, jval = 12345;
	const double dval = 12.3456;

	cout << "ival = " << ival << "\t"
		<< "jval = " << jval << "\t"
		<< "dval = " << dval << endl;

	return;	
}
int main()
{
	cout << showbase;

	cout << "default:" << endl;
	printvalue();

	cout << "printed in octal:" << endl << oct;
	printvalue();

	cout << "printed in hexadecimal:" << endl << hex;
	printvalue();

	cout << "printed in decimal:" << endl << dec;
	printvalue();

	cout << noshowbase;

	return 0;
}
