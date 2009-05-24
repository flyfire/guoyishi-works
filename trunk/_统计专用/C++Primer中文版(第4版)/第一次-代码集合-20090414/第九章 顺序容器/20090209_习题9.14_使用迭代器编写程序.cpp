#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	vector<string> svec;
	string str;

	cout << "Enter strings(Ctrl+Z to end):" << endl;
	while (cin >> str)
		svec.push_back(str);

	vector<string>::iterator iter = svec.begin();
	while (iter != svec.end()) {
		cout << *iter << endl;
		++iter;
	}

	return 0;
}

