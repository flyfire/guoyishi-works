#include <iostream>
#include <utility>
#include <string>
#include <vector>
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
		sipr = pair<string, int>(str, ival);
		pvec.push_back(sipr);
	}

	cout << sipr.first << endl << sipr.second << endl;
	return 0;
}