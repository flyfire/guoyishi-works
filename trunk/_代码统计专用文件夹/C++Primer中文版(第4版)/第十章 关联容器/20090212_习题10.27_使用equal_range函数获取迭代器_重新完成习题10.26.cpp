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
		cout << "Enter author name(Ctrl+Z to end):" << endl;
		cin >> author;

		if (!cin)
			break;

		cout << "Enter author's work(Ctrl+Z to end):" << endl;
		while (cin >> work)
			authors.insert(make_pair(author, work));

		cin.clear();
	} while (cin);

	cin.clear();

	cout << "Who is the author that you want erase:" << endl;
	cin >> searchItem;

	typedef multimap<string, string>::iterator itType;
	pair<itType, itType> pos = authors.equal_range(searchItem);

	if (pos.first != authors.end()) {
		cout << "List:" << endl;
		while (pos.first != pos.second) {
			cout << pos.first->first << " " << pos.first->second << endl;
			++pos.first;
		}
		cout << "Are you sure?(Yes/No)" << endl;
		string answer;
		cin >> answer;
		if (answer[0] == 'Y' || answer[0] == 'y') {
			multimap<string, string>::size_type cnt = authors.erase(searchItem);
			cout << "erase: " << cnt << " " << searchItem << " successful!" << endl;
		}
		else
			cout << "You didn't erase them" << endl;

		/***********erased!!!!!********************
		while (pos.first != pos.second) {
			cout << pos.first->first << " " << pos.first->second << endl;
			++pos.first;
		}
		/************WRONG!!!************************/
	}
	else
		cout << "Can not find this author!" << endl;

	cout << "author\t\twork:" << endl;
	for (itType iter = authors.begin(); iter != authors.end(); ++iter)
		cout << (*iter).first << "\t\t" << (*iter).second << endl;

	return 0;
}