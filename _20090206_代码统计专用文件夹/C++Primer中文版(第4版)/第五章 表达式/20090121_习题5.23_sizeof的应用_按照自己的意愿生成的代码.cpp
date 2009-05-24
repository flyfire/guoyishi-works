#include <iostream>
using namespace std;

int main()
{
	int x[10];
	int *p=x;
	cout << sizeof(x)<< "/" << sizeof(*x) << endl;	//这样就能表示 "/" 符号
	cout << sizeof(p)<< "/" << sizeof(*p) << endl;

	return 0;
}