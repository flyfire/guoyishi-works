#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main()
{
	vector<string> svec;
	list<string> slst;
	string str;

	cout << "Enter some strings for vector container(Ctrl+Z to end):"
		<< endl;
	while (cin >> str)
		svec.push_back(str);

	cin.clear();

	cout << "Enter some strings for list container(Ctrl+Z to end):"
		<< endl;
	while (cin >> str)
		slst.push_back(str);

	cin.clear();

	size_t cnt = 0;
	vector<string>::iterator it = svec.begin();
	while ((it = find_first_of(it, svec.end(), slst.begin(), slst.end())) 
		!= svec.end()) {
		cout << *it << " ";
		++cnt;
		++it;
	}
	cout << endl;

	cout << "Found " << cnt
		<< " names on both rosters" << endl;

	return 0;
}
