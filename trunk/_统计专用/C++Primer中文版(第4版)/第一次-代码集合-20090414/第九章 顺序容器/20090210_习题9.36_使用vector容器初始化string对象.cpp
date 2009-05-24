#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	vector<char> cvec;
	char ch;

	cout << "Enter something(Ctrl+Z to end):" << endl;
	while (cin >> ch)
		cvec.push_back(ch);

	string str;
	str.assign(cvec.begin(), cvec.end());

	//OR
	//	string str(cvec.begin(), cvec.end());

	cout << str << endl;

	return 0;
}