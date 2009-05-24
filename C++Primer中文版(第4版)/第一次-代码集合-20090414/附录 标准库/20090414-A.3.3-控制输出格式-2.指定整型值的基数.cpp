//20090414
#include <iostream>
using namespace std;

void print_out_of_main_function()
{
	cout << 12 << endl;
	cout << 12121212 << endl;

	return;
}

int main()
{
	print_out_of_main_function();

	const int ival = 15, jval = 1024;

	cout << "default: ival = " << ival
		<< " jval = " << jval << endl;

	print_out_of_main_function();

	cout << "printed in hexadecimal: ival = " << hex << ival
		<< " jval = " << jval << endl;

	print_out_of_main_function();

	cout << "printed in octal: ival = " << oct << ival
		<< " jval = " << jval << endl;

	print_out_of_main_function();

	cout << "printed in decimal: ival = " << dec << ival
		<< " jval = " << jval << endl;

	print_out_of_main_function();

	return 0;
}