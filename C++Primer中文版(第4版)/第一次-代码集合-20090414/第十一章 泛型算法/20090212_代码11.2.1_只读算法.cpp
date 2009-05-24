#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
using namespace std;

int main()
{
{
	vector<int> ivec;
	int ival;

	cout << "Enter some integers(Ctrl+Z to end):" << endl;
	while (cin >> ival)
		ivec.push_back(ival);

	cin.clear();

	int sum = accumulate(ivec.begin(), ivec.end(), 0);
	cout << "SUM: " << sum << endl;
}
{
	vector<string> svec;
	string str;
	cout << "Enter some strings(Ctrl+Z to end):" << endl;
	while (cin >> str)
		svec.push_back(str);

	cin.clear();

	string sum = accumulate(svec.begin(), svec.end(), " ");
	cout << "SUM: " << sum;
}
	return 0;
}
