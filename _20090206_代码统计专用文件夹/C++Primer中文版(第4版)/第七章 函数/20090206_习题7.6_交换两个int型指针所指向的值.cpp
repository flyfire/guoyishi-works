#include <iostream>
using namespace std;

void swap(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y =temp;
}

int main()
{
	int xval, yval;
	cout << "Enter two integers:" << endl;
	cin >> xval >> yval;
	cout <<  "Before swapped:"
		<< "\tx= " << xval
		<< "\ty= " << yval << endl;
	swap(&xval, &yval);
	cout << "After swapped:"
		<< "\tx= " << xval
		<< "\ty= " << yval << endl;

	return 0;
}