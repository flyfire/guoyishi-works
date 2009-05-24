//输出每种内置类型的长度
#include <iostream>
using namespace std;

int main()
{
	cout << "type\t\t\t" << "size" << endl
		<< "bool\t\t\t" << sizeof(bool) << endl
		<< "char\t\t\t" << sizeof(char) << endl
		<< "signed char\t\t" << sizeof(signed char) << endl
		<< "unsigned char\t\t" << sizeof(unsigned char) <<endl
		<< "wchar_t\t\t\t" << sizeof(wchar_t) << endl
		<< "short\t\t\t" << sizeof(short) << endl
		<< "signed short\t\t" << sizeof(signed short) << endl
		<< "unsigned short\t\t" << sizeof(unsigned short) << endl
		<< "int\t\t\t" << sizeof(int) << endl
		<< "signed int\t\t" << sizeof(signed int) << endl
		<< "unsigned int \t\t" << sizeof(unsigned int) << endl
		<< "long\t\t\t" << sizeof(long) << endl
		<< "signed long\t\t" << sizeof(signed long) << endl
		<< "unsigned long\t\t" << sizeof(unsigned long) << endl
		<< "float\t\t\t" << sizeof(float) << endl
		<< "double\t\t\t" << sizeof(double) << endl
		<< "long double\t\t" << sizeof(long double) << endl;

	return 0;
}
