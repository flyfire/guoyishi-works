#include <iostream>
#include <utility>
#include <vector>
#include <string>
using namespace std;

int main()
{
	pair<string, int> sipr;
	string str;
	int ival;
	vector< pair<string, int> > pvec;

	cout << "Enter a string and an integer(Ctrl+Z to end):"
		<< endl;
	while (cin >> str >> ival) {
		sipr = make_pair(str, ival);
		pvec.push_back(sipr);
	}

	cout << sipr.first << endl
		<< sipr.second << endl;

	return 0;
}