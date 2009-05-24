#include <iostream>
using namespace std;

int main()
{
	int i, j;
	cout << "Enter two integers for i and j:" << endl;
	cin >> i >> j;
	int *p1 = &i, *p2 = &j;
	cout << "i: " << i << " j: " << j << endl;

	cout << "*p1 = " << *p1 << " p1 = " << p1 << endl;
	cout << "*p2 = " << *p2 << " p2 = " << p2 << endl;

	*p1 = *p2;

	cout << "*p1 = " << *p1 << " *p2 = " << *p2 << endl;
	cout << "i = " << i << " j = " << j << endl;

	return 0;
}
