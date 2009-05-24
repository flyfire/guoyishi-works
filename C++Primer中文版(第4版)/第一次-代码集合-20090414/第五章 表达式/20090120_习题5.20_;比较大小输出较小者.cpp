#include <iostream>
using namespace std;

int main()
{
	cout << "Enter two numbers:";
	int i,j;
	cin >> i >> j;
	cout << "The smaller of " << i << " and " << j
		<< " is " << (i < j ? i : j) << endl;

	return 0;
}
