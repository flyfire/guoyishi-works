#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
using namespace std;

void restricted_wc(ifstream &removeFile, map<string, int> &wordCount)
{
	vector<string> excluded;
	string removeWord;
	while (removeFile >> removeWord)
		excluded.push_back(removeWord);

	cout << "Enter text(Ctrl+Z to end):" << endl;
	string word;
	while (cin >> word) {
		bool find = false;

		vector<string>::iterator iter = excluded.begin();
		while (iter != excluded.end()) {
			if (*iter == word) {
				find = true;
				break;
			}
			++iter;
		}

		if (!find)
			++wordCount[word];
	}
}

int main()
{
	map<string, int> wordCount;
	string fileName;

	cout << "Enter filename:" << endl;
	cin >> fileName;
	ifstream exFile(fileName.c_str());
	if (!exFile) {
		cout << "error: can not open file:" << fileName << endl;
		return -1;
	}

	restricted_wc(exFile, wordCount);

	cout << "word\t\t" << "times" << endl;
	map<string, int>::iterator iter = wordCount.begin();
	while (iter != wordCount.end()) {
		cout << iter->first << "\t\t" << iter->second << endl;
		++iter;
	}

	return 0;
}
