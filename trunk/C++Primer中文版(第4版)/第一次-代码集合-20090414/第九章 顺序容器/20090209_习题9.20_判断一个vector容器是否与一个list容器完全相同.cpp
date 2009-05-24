#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main()
{
	vector<int> ivec;
	list<int> ilst;
	int ival;

	cout << "Enter some integers for vector(Ctrl+Z to end):" << endl;
	while (cin >> ival)
		ivec.push_back(ival);
	cin.clear();

	cout << "Enter some integers for list(Ctrl+Z to end):" << endl;
	while (cin >> ival)
		ilst.push_back(ival);

	vector<int>::iterator vit = ivec.begin();
	list<int>::iterator lit = ilst.begin();
	while (vit != ivec.end() && lit != ilst.end()) {
		if (*vit != *lit)
			break;
		++vit;
		++lit;
	}

	if(vit == ivec.end() && lit == ilst.end())
		cout << "The vector contains the same elements as the list."
		<< endl;
	else
		cout << "List and vector contain different elements."
		<< endl;

	return 0;
}