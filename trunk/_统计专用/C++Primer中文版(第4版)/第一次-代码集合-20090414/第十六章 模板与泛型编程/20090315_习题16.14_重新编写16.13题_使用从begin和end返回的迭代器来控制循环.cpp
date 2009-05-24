#include <iostream>
#include <string>
#include <vector>
using namespace std;

//print function
template <typename Parm>
int print(const Parm& c)
{
	typename Parm::const_iterator iter = c.begin();
	while (iter != c.end()) {
		cout << *iter << " ";
		++iter;
	}
	return 0;
}

int main()
{
	int ival;
	string str;
	vector<int> ivec;
	vector<string> svec;

	//for vector<int>
	cout << "Enter some integers(Ctrl+Z to end):" << endl;
	while (cin >> ival) {
		ivec.push_back(ival);
	}
	cin.clear();

	print(ivec);

	//for vector<string>
	cout << endl;
	cout << "Enter some strings(Ctrl+Z to end):" << endl;
	while (cin >>str) {
		svec.push_back(str);
	}
	cin.clear();

	print(svec);

	return 0;
}
