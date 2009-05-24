//20090414
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int i = -16;
	double d = 3.1415926;
	cout << "i: " << setw(12) << i << " next col" << '\n'
		 << "d: " << setw(12) << d << " next col" << '\n';

	cout << left
		<< "i: " << setw(10) << i << " next col" << '\n'
		<< "d: " << setw(10) << d << " next col" << '\n';

	cout << right
		<< "i: " << setw(8) << i << " next col" << '\n'
		<< "d: " << setw(8) << d << " next col" << '\n';

	cout << internal
		<< "i: " << setw(20) << i << " next col" << '\n'
		<< "d: " << setw(20) << d << " next col" << '\n';

	cout << setfill('@')
		<< "i: " << setw(32) << i << " next col" << '\n'
		<< "d: " << setw(32) << d << " next col" << '\n'
		<< setfill(' ');

	return 0;
}