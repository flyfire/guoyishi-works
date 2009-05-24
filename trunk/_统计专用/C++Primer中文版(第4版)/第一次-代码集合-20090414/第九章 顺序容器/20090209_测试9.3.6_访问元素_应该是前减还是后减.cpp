#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> ivec;
	int ival;

	cout << "Enter some integers(Ctrl+Z to end):" << endl;
	while (cin >> ival)
		ivec.push_back(ival);

	cout << "The last element is :"	<< endl;
	vector<int>::iterator iter = ivec.end();
	cout << *iter << endl;
	cout << *iter-- << endl;
	cout << *(--iter);
	cout << endl;

	return 0;
}