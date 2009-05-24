//20090321 Why the arr_size can not be 881211?
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cout << "TEST $1" << endl;
	const size_t arr_size = 217;
	int int_arr[arr_size];

	for (size_t ix = 0; ix != arr_size; ++ix) {
		int_arr[ix] = ix;
		cout << ix << " ";
	}

	cout << "TEST #1" << endl;	/////////////////////////////////////////////
	vector<int> ivec(int_arr, int_arr + arr_size);
	cout << "TEST #2" << endl;	/////////////////////////////////////////////

	for (vector<int>::iterator iter = ivec.begin();
	iter != ivec.end(); ++iter) {
		cout << *iter << " ";
		if ((iter - ivec.begin()) % 10 == 0 || iter == ivec.end() -1)
			cout << endl;
	}

	return 0;
}