#include "20090208_get.hpp"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream& open_file(ifstream &in, const string &file)
{
	in.close();
	in.clear();
	in.open(file.c_str());
	
	return in;
}

int main()
{
	string fileName, s;

	cout << "Enter filename:" << endl;
	cin >> fileName;

	ifstream inFile;
	if (!open_file(inFile, fileName.c_str())) {
		cout << "error: can not open file: "
			<< fileName << endl;
		return -1;
	}

	get(inFile);
	inFile.close();

	return 0;
}