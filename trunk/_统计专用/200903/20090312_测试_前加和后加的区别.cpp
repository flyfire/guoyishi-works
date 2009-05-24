#include <iostream>
using namespace std;

int main()
{
	int value;

	cout << "Enter a value: " << endl;
	cin >> value;

	cout << "Value++ = " << value++;
	cout << '\t' << value << endl;

	cout << "++Value = " << ++value;
	cout << '\t' << value << endl;

	cout << "Value-- = " << value--;
	cout << '\t' << value << endl;

	cout << "--Value = " << --value;
	cout << '\t' << value << endl;

	return 0;
}