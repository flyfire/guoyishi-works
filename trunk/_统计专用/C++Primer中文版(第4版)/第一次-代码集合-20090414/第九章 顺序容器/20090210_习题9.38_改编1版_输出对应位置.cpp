#include <iostream>
#include <string>
using namespace std;

int main()
{
	string numbers("0123456789");
	string str("ab2c3d7R4E6");

	cout << numbers << endl
		<< str << endl << endl;

	string::size_type pos = 0;
	while (pos != str.size()) {
		if (str.find_first_of(numbers, pos) == pos)
			cout << str.at(pos);
		else
			cout << " ";
		++pos;
	}
	cout << endl;

	pos = 0;
	while (pos != str.size()) {
		if (str.find_first_not_of(numbers, pos) == pos)
			cout << str[pos];
		else
			cout << " ";
		++pos;
	}
	cout << endl << str << endl;

	return 0;
}
