#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	size_t cnt = 10;
	string str;
	vector<string> svec1, svec2;
	cout << "Enter something(How about 10?):" << endl;
	while (cnt--) {
		cin >> str;
		svec1.push_back(str);
	}

	vector<string>::iterator iter1 = svec1.begin();
	for (;iter1 != svec1.end(); ++iter1) {
		svec2.push_back(*iter1);
	}

	for (iter1 = svec1.begin(); iter1 != svec1.end(); ++iter1) {
		cout << *iter1 << " ";
	}
	cout << endl;

	return 0;
}