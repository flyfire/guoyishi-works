#include <iostream>
using namespace std;

int getvalue(int m, int n)
{
	if (m < n)
		return m;
	while (m >= n) {
		m -= n;
	}

	return m;
}

int gcd(int m, int n)
{
	int t;
	while (n != 0) {
		t = getvalue(m, n);
		m = n;
		n = t;
	}

	return m;
}



int main()
{
	cout << "Enter a value:" << endl;

	int m, n;

	cin >> m >> n;

	cout << "GCD = " << gcd(m, n) << endl;

	return 0;
}