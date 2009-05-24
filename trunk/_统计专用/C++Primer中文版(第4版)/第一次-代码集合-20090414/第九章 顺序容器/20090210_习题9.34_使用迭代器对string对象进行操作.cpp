#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	cout << "Enter a string:" << endl;
	cin >> str;

	string::iterator iter = str.begin();
	while (iter != str.end()) {
		*iter = toupper(*iter);
		cout << *iter++ << endl;
	}

	return 0;
}
