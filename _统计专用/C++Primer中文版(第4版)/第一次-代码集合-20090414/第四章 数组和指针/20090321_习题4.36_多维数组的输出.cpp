//20090321 COPY!
#include <iostream>
using namespace std;

int main()
{
	int ia[3][4] = {
		{0, 2, 2, 5},
		{32, 22, 1, 9},
		{12, 3, 2, 232}
	};

	int (*p)[4];
	for (p = ia; p != ia + 3; ++p) {
		for (int *q = *p; q != *p + 4; ++q) {
			cout << *q << "\t";
		}
		cout << endl;
	}
	cout << endl;

	return 0;
}