#include <iostream>
using namespace std;

template <typename T>
T calc(T, T)
{
	cout << "It is me." << endl;

	return 0;
}

int main()
{
	int ival;
	double dval;
	float fval;

	calc(dval, dval);

	calc(ival, dval);	//error

	calc(fval, ival);	//error

	return 0;
}