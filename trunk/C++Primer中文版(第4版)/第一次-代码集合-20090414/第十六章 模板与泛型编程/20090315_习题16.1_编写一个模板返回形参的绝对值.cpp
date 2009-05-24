#include <iostream>
using namespace std;

template <typename T>
T abs(T val)
{
	if (val < 0)
		return -val;
	return val;
}

int main()
{
	short sval = -21;
	int ival = 12;
	float fval = -3.22f;
	double dval = 12.342;

	cout << "Absolute value of " << sval << " is " << abs(sval) << endl;
	cout << "Absolute value of " << ival << " is " << abs(ival) << endl;
	cout << "Absolute value of " << fval << " is " << abs(fval) << endl;
	cout << "Absolute value of " << dval << " is " << abs(dval) << endl;

	return 0;
}