#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	vector<int> ivec;
	int ival;

	cout << "Enter integers(Ctrl+Z to end):" << endl;
	while (cin >> ival)
		ivec.push_back(ival);

	cin.clear();

	cout << "Enter the search item:" << endl;
	int searchItem;
	cin >> searchItem;

	cout << count(ivec.begin(), ivec.end(), searchItem)
		<< " times " << searchItem << " Find" << endl;

	return 0;
}