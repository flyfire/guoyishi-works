#include <iostream>
using namespace std;

int main()
{
	const int array_size = 10;
	int ia[array_size];
	
	size_t ix;
	for (ix = 0; ix != array_size; ++ix) {
		ia[ix] = ix;
	}

	for (ix =0; ix != array_size; ++ix) {
		cout << ia[ix] << " ";
	}
	cout << endl;

	return 0;
}