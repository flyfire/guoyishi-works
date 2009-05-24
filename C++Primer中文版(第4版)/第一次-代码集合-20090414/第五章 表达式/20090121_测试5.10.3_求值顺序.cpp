#include <iostream>
using namespace std;

int main()
{
	int ival;
	ival=5;
	if(ival++ < ival)
		cout << "Left first!" << endl;
	else if(ival++ == ival)
		cout << "Right first!" << endl;

	return 0;
}
