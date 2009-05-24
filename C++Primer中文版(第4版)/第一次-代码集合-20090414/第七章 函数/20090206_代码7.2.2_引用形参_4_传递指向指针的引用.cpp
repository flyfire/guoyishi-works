#include <iostream>
using namespace std;

void ptrswap(int *&v1, int *&v2)
{
	int *tmp = v2;
	v2 = v1;
	v1 = tmp;
}

int main()
{
	int i = 10;
	int j = 20;
	int *pi = &i;
	int *pj = &j;
	cout << "Before ptrswap():\t*pi: "
		<< *pi << "\t*pj: " << *pj << endl;
	ptrswap(pi, pj);
	cout << "After ptrswap():\t*pi: "
		<< *pi << "\t*pj: " << *pj << endl;

	return 0;
}
