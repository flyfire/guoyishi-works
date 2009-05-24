#include <iostream>
#include <set>
#include <map>
#include <string>
using namespace std;

int main()
{
	multimap<string, string> authors;
	string author, book;

	cout << "Enter some items(Ctrl+Z to end):" << endl;
	while (cin >> author >> book)
		authors.insert(make_pair(author, book));
	
	cin.clear();

	string search_item;
	cout << "Enter search item(Ctrl+Z to end):" << endl;
	cin >> search_item;
	multimap<string, string>::iterator iter = authors.find(search_item);

	if (iter != authors.end()) {
		multimap<string, string>::size_type cnt = authors.erase(search_item);
		if (cnt)
			cout << "erase: " << cnt << " " << search_item <<  " successful!" << endl;
	}
	else
		cout << "can not find: " << search_item << endl;

	return 0;
}

