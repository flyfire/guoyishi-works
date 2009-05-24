#include <iostream>
using namespace std;

int main()
{
	int x[10];
	int *p=x;
	cout << sizeof(x)/sizeof(*x) << endl;		//其实 "/" 表示了一个除法运算
	cout << sizeof(p)/sizeof(*p) << endl;

	return 0;
}