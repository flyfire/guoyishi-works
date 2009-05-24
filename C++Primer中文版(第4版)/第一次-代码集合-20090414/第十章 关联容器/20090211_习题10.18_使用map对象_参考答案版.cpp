#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int main()
{
	map< string, vector<string> > children;
	string surName, childName;

	do {
		cout << "Enter surname(Ctrl+Z to end):" << endl;
		cin >> surName;
		if (!cin)
			break;
		vector<string> chd;
		pair<map<string, vector<string> >::iterator, bool> ret = 
			children.insert(make_pair(surName, chd));
		
		if (!ret.second) {
			cout << "repeated surname: " << surName << endl;
			continue;
		}

		cout << "Enter children's name(Ctrl+Z to end):" << endl;
		while (cin >> childName)
			ret.first->second.push_back(childName);
		cin.clear();
	} while (cin);

	cin.clear();

	cout << "Enter a surname to search:" << endl;
	cin >> surName;

	map<string, vector<string> >::iterator iter =
		children.find(surName);

	if (iter == children.end())
		cout << "no this surname: " << surName << endl;
	else {
		cout << "children: " << endl;
		vector<string>::iterator it = iter->second.begin();
		while (it != iter->second.end())
			cout << *it++ << endl;
	}

	return 0;
}