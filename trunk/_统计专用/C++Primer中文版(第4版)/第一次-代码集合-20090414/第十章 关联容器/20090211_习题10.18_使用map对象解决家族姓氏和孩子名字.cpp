#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main()
{
	map<string, vector<string> > children;
	string surName, childName;

	cout << "Enter children's name(Ctrl+Z to end):" << endl;
	while (cin >> childName >> surName) {
		map<string, vector<string> >::iterator iter = children.find(surName);
		if (iter != children.end())
			(iter->second).push_back(childName);
		else {
			vector<string> child;
			child.push_back(childName);
			children.insert(make_pair(surName, child));
		}
	}

	cout << "Children:" << endl;
	map<string, vector<string> >::iterator child_it = children.begin();
	while (child_it != children.end()) {
		cout << child_it->first << ":" << endl;
		vector<string>::iterator vit = (child_it->second).begin();
		while (vit != (child_it->second).end()) {
			cout << "\t\t\t" << *vit << endl;
			++vit;
		}
		++child_it;
	}

	return 0;
}


