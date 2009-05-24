//20090414
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	cout << sqrt(2.0) << endl;
	
	cout << "scientific: " << scientific << sqrt(2.0) << endl
		<< "fixed decimal: " << fixed << sqrt(2.0) << endl;

	cout << uppercase
		<< "scientific: " << scientific << sqrt(2.0) << endl
		<< "fixed decimal: " <<  fixed << sqrt(2.0) << endl;

	cout << nouppercase;

	cout << sqrt(2.0) << endl;
	cout.unsetf(ostream::floatfield);
	cout << '\n' << sqrt(2.0) << endl;

	return 0;
}
