#include <iostream>
using namespace std;

int main()
{
	int i,j,k;
	cout << "Enter three numbers:";
	cin >> i >> j >> k;
	int max = i > j
		? i > k ? i : k
		: j > k ? j : k;

	cout << "Max = " << max << endl;

	return 0;
}