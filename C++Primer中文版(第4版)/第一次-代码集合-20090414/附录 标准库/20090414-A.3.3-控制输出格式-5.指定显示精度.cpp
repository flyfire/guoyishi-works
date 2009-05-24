//20090414
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	cout << "Precision: " << cout.precision()
		<< "\t Value: " << sqrt(2.0) << endl;

	cout.precision(12);
	cout << "Precision: " << cout.precision()
		<< "\t Value: " << sqrt(2.0) << endl;

	cout.precision(4);
	cout << "Precision: " << cout.precision()
		<< "\t Value: " << sqrt(2.0) << endl;

	return 0;
}