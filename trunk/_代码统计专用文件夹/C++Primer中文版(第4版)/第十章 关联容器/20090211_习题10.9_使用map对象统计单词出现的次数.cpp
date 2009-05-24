#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	map<string, int> word_count;
	string str;

	cout << "Enter words(Ctrl+Z to end):" << endl;
	while (cin >> str) {
		++word_count[str];
	}

	cout << "WORD:\t\tTIMES:" << endl;
	map<string, int>::iterator iter = word_count.begin();
	while (iter != word_count.end()) {
		cout << (*iter).first << "\t\t"	//	(*iter).first
			<< (*iter).second << endl;	//	(*iter).second
		++iter;
	}

	return 0;
}
