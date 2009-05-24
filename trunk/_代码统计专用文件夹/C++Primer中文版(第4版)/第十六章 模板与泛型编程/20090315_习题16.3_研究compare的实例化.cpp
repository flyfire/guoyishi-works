#include <iostream>
#include <string>
using namespace std;

template <typename T>
string compare(T v1, T v2)
{
	if (v1 < v2)
		return " < ";
	if (v1 > v2)
		return " > ";
	else
		return " = ";
}

int main()
{
	string s1, s2;
	cout << "Enter two strings:" << endl;
	cin >> s1 >> s2;

	cout << s1 << compare(s1, s2) << s2 << endl;

	cout << s1 << compare(s1.c_str(), s2.c_str()) << s2 << endl;

	cout << "first" << compare("first", "second") << "second" << endl;

	return 0;
}