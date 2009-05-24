#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename Parm>
void print(const Parm& c)
{
	typename Parm::size_type index = 0;
	while (index != c.size()) {
		cout << c[index] << " ";
		++index;
	}
}

int main()
{
	int ival;
	string str;

	vector<int> ivec;
	vector<string> svec;

	cout << "Enter some integers(Ctrl+Z to end):" << endl;
	while (cin >> ival) {
		ivec.push_back(ival);
	}
	cin.clear();

	print(ivec);

	cout << "\nEnter some strings(Ctrl+Z to end):" << endl;
	while (cin >> str) {
		svec.push_back(str);
	}
	cin.clear();

	print(svec);

	return 0;
}