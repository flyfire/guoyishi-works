#include <iostream>
#include <map>
#include <utility>
#include <string>
using namespace std;

int main()
{
	map<string, int> words_count;
	string str;
	pair<map<string, int>::iterator, bool> ret;

	cout << "Enter some words(Ctrl+Z to end):" << endl;
	while (cin >> str) {
		ret = words_count.insert(make_pair(str, 1));
		if (!ret.second)
			++ret.first->second;
	}

	cout << "WORD:\t\t" << "TIMES:" << endl; 
	map<string, int>::iterator iter = words_count.begin();
	while (iter != words_count.end()) {
		cout << (*iter).first << "\t\t"
			<< (*iter).second << endl;
		++iter;
	}

	return 0;
}
