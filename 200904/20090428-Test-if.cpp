#include <iostream>
using namespace std;

int main()
{
	int value;
	cout << "Enter an integer:";
	cin >> value;

	//Test:
	if (value >= 10 && value <= 0) {
		cout << "No way!" << endl;
	}
	else
		cout << "Hello!" << endl;

	return 0;
}
