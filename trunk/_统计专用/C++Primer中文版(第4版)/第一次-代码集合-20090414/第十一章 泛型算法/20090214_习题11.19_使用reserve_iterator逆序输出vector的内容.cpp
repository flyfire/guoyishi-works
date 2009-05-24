#include <iostream>
#include <string>
#include <vector>
#include <iterator>
using namespace std;

int main()
{
	vector<string> svec;
	string str;

	cout << "Enter some strings(Ctrl+Z to end):" << endl;
	while (cin >> str)
		svec.push_back(str);
	cin.clear();

	vector<string>::reverse_iterator r_iter = svec.rbegin();
	while (r_iter != svec.rend())
		cout << *r_iter++ << " ";
	cout << endl;

	return 0;
}