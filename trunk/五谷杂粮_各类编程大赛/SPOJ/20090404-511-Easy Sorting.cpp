#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	while (n--) {
		int m;
		cin >> m;
		string str;
		vector<string> svec;
		while (m--) {
			cin >> str;
			svec.push_back(str);
		}
		sort(svec.begin(), svec.end());
		for (vector<string>::const_iterator iter = svec.begin();
		iter != svec.end(); ++iter) {
			cout << *iter << endl;
		}
	}
}
