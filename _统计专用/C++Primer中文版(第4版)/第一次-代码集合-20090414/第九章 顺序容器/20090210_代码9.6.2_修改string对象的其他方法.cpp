#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s = "some string";
	string s2 = "some other string";

	cout << s << endl << s2 << endl << endl;

	s.insert(s.begin(), s2.begin(), s2.end());

	cout << s << endl << s2 << endl << endl;

	s.insert(0, s2);

	cout << s << endl << s2 << endl << endl;

	s.insert(0, s2, 0, s2.size());

	cout << s << endl << s2 << endl << endl;

	return 0;
}