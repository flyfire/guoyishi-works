#include <iostream>
#include <algorithm>
#include <iterator>
#include <list>
#include <vector>
using namespace std;

int main()
{
	list<int> ilst;
	int ival;

	cout << "Enter some integers(Ctrl+Z to end):" << endl;
	while (cin >> ival)
		ilst.push_back(ival);
	cin.clear();

	cout << "unique integers:" << endl;

	vector<int> ivec;
	unique_copy(ilst.begin(), ilst.end(), back_inserter(ivec));

	/*
	sort(ivec.begin(), ivec.end());

	vector<int>::iterator end_unique = unique(ivec.begin(), ivec.end());

	ivec.erase(end_unique, ivec.end());
	*/

	vector<int>::iterator iter = ivec.begin();
	while (iter != ivec.end())
		cout << *iter++ << " ";
	cout << endl;

	return 0;
}