#include <iostream>
using namespace std;

int main()
{
	cout << "Enter number:";
	int ival;
	cin >> ival;
	if(ival%2)
		cout << "The number " << ival << " is a JI" << endl;
	else
		cout << "The number " << ival << " is a OU" << endl;

	return 0;
}