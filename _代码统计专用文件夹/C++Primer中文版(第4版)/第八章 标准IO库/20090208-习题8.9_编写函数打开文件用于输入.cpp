#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int fileToVector(string fileName, vector<string>& svec)
{
	ifstream inFile(fileName.c_str());
	if(!inFile)
		return 1;
	string s;
	while (getline(inFile,s))
		svec.push_back(s);
	inFile.close();
	if (inFile.eof())
		return 4;
	if (inFile.bad())
		return 2;
	if (inFile.fail())
		return 3;
}

int main()
{
	vector<string> svec;
	string fileName, s;

	cout << "Enter filename:" << endl;
	cin >> fileName;

	switch(fileToVector(fileName, svec)) {
	case 1:
		cout << "error: can not open file: "
			<< fileName << endl;
		return -1;
	case 2:
		cout << "error: system failure " << endl;
		return -1;
	case 3:
		cout << "error: read failure " << endl;
		return -1;
	}

	cout << "Vector:" << endl;
	for (vector<string>::iterator iter = svec.begin();iter != svec.end(); ++iter)\
		cout << *iter << endl;

	return 0;
}