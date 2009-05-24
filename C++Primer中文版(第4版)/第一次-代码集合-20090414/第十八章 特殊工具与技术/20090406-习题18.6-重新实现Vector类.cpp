#include "20090406-Vector-b.hpp"
#include <iostream>
using namespace std;

int main()
{
	Vector<int> iVec;

	int i;
	for (i = 0; i != 10; ++i)
		iVec.push_back(i);

	for (i = 0; i != 10; ++i)
		iVec[i];

	return 0;
}