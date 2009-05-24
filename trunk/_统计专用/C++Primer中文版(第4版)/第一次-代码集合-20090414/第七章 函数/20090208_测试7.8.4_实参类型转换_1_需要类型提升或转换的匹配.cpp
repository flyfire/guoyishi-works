#include <iostream>

void fun(int v2)
{
	return;
}
void fun(short v1)
{
	return;
}

int main()
{
	short val = 0;
	fun(val);

	char ch = 'A';
	fun(ch);

	return 0;
}