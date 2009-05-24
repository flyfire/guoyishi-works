#include "20090406-Vector.hpp"
#include <iostream>
using namespace std;

int main()
{
	int ival;
	Vector<int> iVec;
	while (cin >> ival) {
		iVec.push_back(ival);
	}

	int i;
	for (i = 0; i != iVec.size(); ++i)
		cout << iVec[i] << endl;

	cout << "iVec.size(): " << iVec.size() << endl;
	cout << "iVec.capacity(): " << iVec.capacity() << endl;

	return 0;
}
