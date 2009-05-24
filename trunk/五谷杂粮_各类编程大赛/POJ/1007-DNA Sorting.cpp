//20090405
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	multimap<int, string> is_map;
	while (m--) {
		string str;
		cin >> str;
		int count = 0;
		for (int i = 0;	i != n; ++i) {
			for (int j = i; j != n; ++j) {
				if (str[i] > str[j]) {
					++count;
				}
			}
		}
		is_map.insert(make_pair(count, str));
	}

	for (multimap<int, string>::const_iterator map_it = is_map.begin();
	map_it != is_map.end(); ++map_it) {
		cout << map_it->second << endl;
	}

	return 0;
}
