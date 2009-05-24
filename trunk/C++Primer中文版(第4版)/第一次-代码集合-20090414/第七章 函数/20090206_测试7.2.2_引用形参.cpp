#include <iostream>
using namespace std;

void swap(int &val)
{
	val*=2;
}
int main()
{
	int ival;

	//Get
	cout << "Enter number:" << endl;
	cin >> ival;

	//Change
	swap(ival);

	//Put
	cout << "Changed the number you enter:" << endl;
	cout << ival << endl;

	return 0;
}