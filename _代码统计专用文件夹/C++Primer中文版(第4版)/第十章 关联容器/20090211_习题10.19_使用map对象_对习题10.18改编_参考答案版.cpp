#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int main()
{
	map< string, vector< pair<string, string> > > children;
	string surname, childName, birthday;

	do {
		cout << "Enter surname(Ctrl+Z to end):" << endl;
		cin >> surname;

		if(!cin)
			break;
		vector< pair<string, string> >chd;
		pair<map<string, vector< pair<string, string> > >::iterator, bool> ret =
			children.insert(make_pair(surname, chd));
		if (!ret.second) {
			cout << "repeat surname: " << surname << endl;
			continue;
		}

		cout << "Enter children's name and birthday(Ctrl+Z to end):"
			<< endl;

		while (cin >> childName >> birthday) {
			ret.first->second.push_back(make_pair(childName, birthday));
		}
		cin.clear();
	} while (cin);

	cin.clear();

	cout << "Enter a surname to search:" << endl;
	cin >> surname;

	map<string, vector< pair<string, string> > >::iterator iter;
	iter = children.find(surname);

	if (iter == children.end())
		cout << "no this surname: " << surname << endl;
	else {
		cout << "children\t\tbirthday" << endl;
		vector< pair<string, string> >::iterator it =
			iter->second.begin();
		while (it != iter->second.end()) {
			cout << it->first << "\t\t" << it->second << endl;
			it++;
		}
	}

	return 0;
}