#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> ivec;
	int ival;

	cout << "Enter some integers(Ctrl+Z to end):" << endl;
	while (cin >> ival)
		ivec.push_back(ival);
	cin.clear();

	list<int> ilst;
	reverse_copy(ivec.begin()+2, ivec.begin()+7, inserter(ilst, ilst.begin()));

	for (list<int>::iterator iter = ilst.begin(); iter != ilst.end(); ++iter)
		cout << *iter << " ";
	cout << endl;

	return 0;
}