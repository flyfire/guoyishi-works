#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>
using namespace std;

void print(list<int>::iterator beg, list<int>::iterator end)
{
	while (beg != end)
		cout << *beg++ << " ";
	cout << endl;
}

int main()
{
	vector<int> ivec;
	int ival;

	cout << "Enter some integers(Ctrl+Z to end):" << endl;
	while (cin >> ival)
		ivec.push_back(ival);
	cin.clear();

	int chg1, chg2;
	cout << "Enter #1 -> #2" << endl;
	cin >> chg1 >> chg2;

	list<int> ilst, ilst2, ilst3;

	replace_copy (ivec.begin(), ivec.end(),
		inserter (ilst, ilst.begin()), chg1, chg2);
	replace_copy (ivec.begin(), ivec.end(),
		back_inserter (ilst2), chg1, chg2);
	replace_copy (ivec.begin(), ivec.end(),
		front_inserter (ilst3), chg1, chg2);

	print(ilst.begin(), ilst.end());
	print(ilst2.begin(),ilst2.end());
	print(ilst3.begin(),ilst3.end());

	return 0;
}
