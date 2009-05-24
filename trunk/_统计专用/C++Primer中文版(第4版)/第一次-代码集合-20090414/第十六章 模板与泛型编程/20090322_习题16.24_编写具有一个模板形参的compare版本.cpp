#include <iostream>
using namespace std;

template <typename T>
int compare(const T& v1, const T& v2)
{
	if (v1 < v2) return -1;
	if (v2 < v1) return 1;
	return 0;
}

int main()
{
	short sval = 512;
	int ival = 1024;
	cout << compare(static_cast<int>(sval), ival) << endl;
	cout << compare(sval, static_cast<short>(ival)) << endl;
	cout << compare<int>(sval, ival) << endl;

	return 0;
}