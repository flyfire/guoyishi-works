//20090414
#include <iostream>
using namespace std;

int main()
{
	const ival = 123, jval = 12345;

	cout << uppercase << showbase << hex
		<< "printed in hexadecimal:" << endl
		<< "ival = " << ival << "\t"
		<< "jval = " << jval << endl
		<< nouppercase << endl;

	cout << "ival = " << ival << "\t" 
		<< "jval = " << jval << endl;

	return 0;
}