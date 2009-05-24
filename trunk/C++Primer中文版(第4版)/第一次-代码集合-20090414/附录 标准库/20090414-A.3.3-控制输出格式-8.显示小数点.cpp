//20090414
#include <iostream>
using namespace std;

int main()
{
	cout << 10.0 << endl;
	cout << showpoint << 10.0 << '\t'
		<< noshowpoint << 10.0 << endl;

	cout.precision(30);
	cout << 10.0 << endl;
	cout << showpoint << 12.3456 << '\t'
		<< noshowpoint << 10.0 << endl;

	return 0;
}
