#include <iostream>
#include <string>
using namespace std;

int main()
{
	string in_str;
	cout << "Enter something:" << endl;
	cin >> in_str;

	size_t len = in_str.size();

	char *str = new char[len];
	for (size_t ix = 0; ix != len; ++ix) {
		str[ix] = in_str[ix];
	}

	cout << "in_str: " << in_str << endl;
	cout << "str: " << str << endl;

	delete [] str;
	return 0;
}
