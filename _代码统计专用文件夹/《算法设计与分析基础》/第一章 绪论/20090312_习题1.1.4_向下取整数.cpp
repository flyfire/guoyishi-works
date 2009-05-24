#include <iostream>
using namespace std;

int main()
{
	int n;

	cout << "Enter a number:" << endl;

	cin >> n;

	int t;

	t = n / 2;

	while (t * t > n) {
		cout << "TEST!  t = " << t << "t * t = " << t * t << endl;
		--t;
	}

	cout << "t = " << t++ << " t * t = " << t * t << " n = " << n << endl;

	return 0;
}