#include <iostream>
using namespace std;

int main()
{
	int ival;
	cout << "Enter an integer:" << endl;
	cin >> ival;

	cout << dec << "ival(dec): " << ival << endl;
	cout << hex << "ival(hex): " << ival << endl;
	//cout << HEX << "ival(HEX): " << ival << endl;
	cout << oct << "ival(oct): " << ival << endl; 

	return 0;
}