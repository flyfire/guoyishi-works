#include <iostream>
#include <string>
using namespace std;

int main()
{
	string numbers("0123456789");
	string str("ab2c3d7R4E6");

	cout << numbers << endl
		<< str << endl;
	
	//
	cout << "Numbers:" << endl;
	string::size_type pos = 0;
	while ((pos = str.find_first_of(numbers, pos)) != string::npos) {
		cout << str[pos] << " ";
		++pos;
	}
	cout << endl;

	//
	cout << "Non Numbers:" << endl;
	pos = 0;
	while ((pos = str.find_first_not_of(numbers, pos)) != string::npos) {
		cout << str[pos] << " ";
		++pos;
	}
	cout << endl;

	return 0;
}