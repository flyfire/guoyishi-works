#include <iostream>
#include <utility>	//NOTICE!
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
		sipr = make_pair(str, ival);
		pvec.push_back(sipr);	
	}

	return 0;
}