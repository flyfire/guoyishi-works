//20090321 update of 4.34
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
	cin.clear();

	char **parr = new char*[svec.size()];

	size_t ix = 0;
	for (vector<string>::iterator iter = svec.begin();
	iter != svec.end(); ++iter) {
		char *p = new char[(*iter).size() + 1];
		strcpy(p, (*iter).c_str());
		parr[ix++] = p;
	}

	cout << "Content of vector:" << endl;
	for (vector<string>::iterator iter2 = svec.begin();
	iter2 != svec.end(); ++iter2) {
		cout << *iter2 << " ";
	}
	cout << endl;

	cout << "Content of character arrays:" << endl;
	for (ix = 0; ix != svec.size(); ++ix) {
		cout << parr[ix] << " ";
	}
	cout << endl;

	for (ix = 0; ix != svec.size(); ++ix) {
		delete [] parr[ix];
	}

	delete [] parr;

	return 0;
}