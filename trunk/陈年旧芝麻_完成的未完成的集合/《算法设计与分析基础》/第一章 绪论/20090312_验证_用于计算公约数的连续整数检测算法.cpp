#include <iostream>
using namespace std;

bool exam(int m, int n)
{
	if (m <= 0 || n <= 0)
		return false;
	return true;
}

int min(int m, int n)
{
	return m < n ? m : n;
}

int gcd(int m, int n)
{
	int tmp;
	tmp = min(m, n);

	while (m % tmp != 0) {
		--tmp;
	}
	while (n % tmp != 0) {
		--tmp;
	}

	while (m % tmp != 0) {
		--tmp;
	}

	while (n % tmp != 0) {
		--tmp;
	}

	return tmp;
}

int main()
{
	cout << "Enter two numbers(m and n):" << endl;

	int m,n;

	cin >> m >> n;

	if (!exam(m, n)) {
		cout << "Wrong input!" << endl;
		return -1;
	}


	cout << "GCD = " << gcd(m, n) << endl;
	cout << "m = " << m << " n = " << n << endl;

	return 0;
}