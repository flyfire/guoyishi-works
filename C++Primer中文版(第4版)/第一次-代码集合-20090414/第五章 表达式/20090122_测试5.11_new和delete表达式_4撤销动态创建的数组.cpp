#include <iostream>
#include <string>
using namespace std;

int main()
{
	int i;
	int *pi=&i;
	string str="dwarves";
	double *pd=new double(33);
	delete str;	//error
	delete pi;	//error
	delete pd;	//ok

	return 0;
}