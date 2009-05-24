#include <iostream>
#include <algorithm>
#include <list>
#include <string>
#include <fstream>
#include <iterator>
using namespace std;

int main()
{
	string inFileName;

	cout << "Enter input file name:" << endl;
	cin >> inFileName;
	ifstream inFile(inFileName.c_str());
	if (!inFile) {
		cout << "Can not open file!" << endl;
		return EXIT_FAILURE;
	}

	//	string outFileName;
	//	cout << "Enter output file name:" << endl;
	//	cin >> outFileName;
	//	ofstream outFile(outFileName.c_str());
	//	if (!outFile) {
	//		cout << "Can not open output file!" << endl;
	//		return EXIT_FAILURE;
	//	}
	
	//	ostream_iterator<string> outIter(outFileName.c_str(), "\n");

	list<string> words;
	string word;
	while (inFile >> word) {
		words.push_back(word);
	//		*outIter++ = word;
	}


	words.sort();

	words.unique();

	for (list<string>::iterator iter = words.begin(); iter != words.end(); ++iter)
		cout << *iter << " ";
	cout << endl;

	return 0;
}
