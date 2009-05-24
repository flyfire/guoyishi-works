#include <iostream>
#include <string>
using namespace std;

template <typename T>
string compare(const T &v1, const T &v2) {
	if (v1 < v2)
		return " < ";
	if (v2 < v1)
		return " > ";
	return  " = ";
}

int main()
{
	int v1, v2;
	cout << "Enter two numbers" << endl;
	cin >> v1 >> v2;

	cout << v1 << compare(v1, v2) << v2 << endl;

	string s1, s2;
	cout << "Enter two strings" << endl;
	cin >> s1 >> s2;

	cout << s1 << compare(s1, s2) << s2 << endl;

	return 0;
}
