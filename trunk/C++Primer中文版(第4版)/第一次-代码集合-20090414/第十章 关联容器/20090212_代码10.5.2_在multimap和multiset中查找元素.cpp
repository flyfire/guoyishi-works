#include <iostream>
#include <set>
#include <map>
#include <string>
using namespace std;

int main()
{
	multimap<string, string> authors;
	string author, book;

	cout << "Enter items(Ctrl+Z to end):" << endl;
	while (cin >> author >> book) {
		authors.insert(make_pair(author, book));
	}
	
	cin.clear();

	string search_item;
	typedef multimap<string, string>::size_type sz_type;
	typedef multimap<string, string>::iterator it_type;

{	//方法一
	cout << "#1 Enter search items(Ctrl+Z to end):" << endl;
	cin >> search_item;
	sz_type entries = authors.count(search_item);
	it_type iter = authors.find(search_item);

	for(sz_type cnt = 0; cnt != entries; ++iter, ++cnt) {
		cout << iter->second << endl;
	}
}
{	//方法二
	cout << "#2 Enter search items(Ctrl+Z to end):" << endl;
	cin >> search_item;
	it_type beg = authors.lower_bound(search_item);
	it_type end = authors.upper_bound(search_item);

	while (beg != end) {
		cout << beg->second << endl;
		++beg;
	}
}
{	//方法三
	cout << "#3 Enter search items(Ctrl+Z to end):" << endl;
	cin >> search_item;
	pair<it_type, it_type> iter = authors.equal_range(search_item);	//注意!
	while (iter.first != iter.second) {
		cout << iter.first->second << endl;
		++iter.first;
	}
}
	return 0;
}
