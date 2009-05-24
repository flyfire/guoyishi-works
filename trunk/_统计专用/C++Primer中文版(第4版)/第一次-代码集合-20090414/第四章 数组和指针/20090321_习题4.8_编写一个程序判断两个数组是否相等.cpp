#include <iostream>
using namespace std;

int main()
{
	const int arr_size = 6;
	int ia1[arr_size], ia2[arr_size];
	size_t ix;

	cout << "Enter " << arr_size << " numbers for array1:" << endl;
	for (ix = 0; ix != arr_size; ++ix) {
		cin >> ia1[ix];
	}
	cout << "Enter " << arr_size << " numbers for array2:" << endl;
	for (ix = 0; ix != arr_size; ++ix) {
		cin >> ia2[ix];
	}

	bool flag = true; 
	for (ix = 0; ix != arr_size; ++ix) {
		if (ia1[ix] != ia2[ix]) {
			flag = false;
			break;
		}
	}

	if (flag)
		cout << "Array1 is equal to array2." << endl;
	else
		cout << "Array1 is not equal to array2." << endl;

	return 0;
}