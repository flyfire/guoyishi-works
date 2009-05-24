#include "20090208_get.hpp"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	string fileName;
	cout << "Enter file name:" << endl;
	cin >> fileName;
	ifstream inFile(fileName.c_str());
	if (!inFile) {
		cerr << "error: can not open input file: "
			<< fileName << endl;
		return -1;
	}
	get(inFile);

	return 0;
}
