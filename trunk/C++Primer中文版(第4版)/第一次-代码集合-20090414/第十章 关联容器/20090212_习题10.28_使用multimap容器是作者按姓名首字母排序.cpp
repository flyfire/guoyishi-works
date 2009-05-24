#include <iostream>
#include <set>
#include <map>
#include <string>
using namespace std;

int main()
{
	multimap<string, string> authors;
	string author, work, searchItem;

	do {
		cout << "Enter author(Ctrl+Z to end):" << endl;
		cin >> author;

		if (!cin)
			break;

		cout << "Enter author's work(Ctrl+Z to end):" << endl;
		while (cin >> work) {
			authors.insert(make_pair(author, work));
		}

		cin.clear();
	} while (cin);

	cin.clear();

	multimap<string, string>::iterator iter = authors.begin();

	while (iter != authors.end()) {
		string str;
		str = iter->first;
		str.resize(1);

		cout << "Author Name Beginning with \"" << str << "\"" << endl;

		while (1) {		//第一层循环
			string str2, str3;
			str2 = str3 = iter->first;
			str2.resize(1);

			if (str == str2) {
				cout << iter->first << ":";
				while(1){	//第二层循环
					string str4;
					str4 = iter->first;
					if (str4 == str3) {
						cout << "," << iter->second;
					}
					else {
						break;
					}
					++iter;
				}
			}
			else {
				break;
			}
			++iter;
		}
		cout << endl;
	}

	return 0;
}
