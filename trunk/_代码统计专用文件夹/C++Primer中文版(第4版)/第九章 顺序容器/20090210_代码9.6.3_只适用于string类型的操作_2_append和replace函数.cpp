#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s("C++ Primer");

	cout << s << endl;

	s.append(" 3rd Ed.");

	cout << s << endl;

	s.replace(11, 3, "4th");

	cout << s << endl;

	s.replace(11, 3, "Fourth");

	cout << s << endl;

	return 0;
}

