#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	pair<string, int> sipr;
	vector<string> svec;
	vector<int> ivec;
	string str;
	int ival;

	cout << "Enter string and integer(Ctrl+Z to end):" << endl;
	while (cin >> str >> ival) {
		sipr = make_pair(str, ival);
		svec.push_back(sipr.first);
		ivec.push_back(sipr.second);
	}

	vector<string>::iterator iter = svec.begin();
	vector<int>::iterator it = ivec.begin();
	while (iter != svec.end()) {
		cout << *iter++ << "\t" << *it++ << endl;
	}

	return 0;
}

