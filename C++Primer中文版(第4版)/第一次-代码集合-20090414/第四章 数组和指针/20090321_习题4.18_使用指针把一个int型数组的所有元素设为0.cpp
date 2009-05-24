//20090321
#include <iostream>
using namespace std;

int main()
{
	const size_t arr_size = 8;
	int int_arr[arr_size] = {0, 1, 2, 3, 4, 5, 6, 7};

	//pointer
	int *pbegin, *pend;

	//print original array
	for (pbegin = int_arr, pend = int_arr + arr_size; pbegin != pend; ++pbegin)
		cout << *pbegin << " ";
	cout << endl;

	//change the value
	for (pbegin = int_arr; pbegin != pend; ++pbegin)
		*pbegin = 0;

	//print changed array
	for (pbegin = int_arr; pbegin != pend; ++pbegin)
		cout << *pbegin << " ";
	cout << endl;

	return 0;
}