#include <iostream>
#include <algorithm>
#include <string>
#include <list>
using namespace std;

int main()
{
	string sval, searchValue;
	list<string> slst;

	cout << "Enter some strings(Ctrl+Z to end):" << endl;
	while (cin >> sval)
		slst.push_back(sval);

	cin.clear();

	cout << "Enter a string you want to search:" << endl;
	cin >> searchValue;

	cout << count(slst.begin(), slst.end(), searchValue)
		<< " elements in the list are \""
		<< searchValue << "\"" << endl;

	return 0;
}