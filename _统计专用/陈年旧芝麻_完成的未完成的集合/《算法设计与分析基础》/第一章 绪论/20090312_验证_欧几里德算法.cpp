#include <iostream>
using namespace std;

bool exam(int m, int n)
{
	if (m <=0 || n <= 0)
		return false;
	return true;
}

int gcd(int m, int n)
{
	int tmp;

	while ( n != 0) {
		tmp = m % n;
		m = n;
		n = tmp;
	}

	return m;
}

int main()
{
	int m, n;

	cout << "Enter two numbers(m and n):" << endl;
	cin >> m >> n;

	if (!exam(m, n)) {
		cout << "Wrong input!" << endl;
		return -1;
	}

	cout << "GCD = " << gcd(m, n) << endl;

	return 0;
}