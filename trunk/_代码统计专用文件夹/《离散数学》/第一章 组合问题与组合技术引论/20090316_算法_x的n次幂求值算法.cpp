#include <iostream>
using namespace std;

int main()
{
	int x, n;
	cout << "Enter x and n" << endl;
	cin >> x >> n;

	int p = x, k = 1;
	while (k < n) {
		p *= x;
		++k;
	}

	cout << "P = " << p << endl;

	return 0;
}