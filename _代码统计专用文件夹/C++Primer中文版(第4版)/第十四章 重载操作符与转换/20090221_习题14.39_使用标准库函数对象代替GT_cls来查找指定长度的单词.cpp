#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
using namespace std;

string make_plural(size_t ctr, const string &word, const string &ending)
{
	return (ctr == 1) ? word : word + ending;
}

int main()
{
	//open intput file
	string fileName;
	cout << "Enter file name:" << endl;
	cin >> fileName;
	ifstream inFile(fileName.c_str());
	
	//get words
	vector<string> words;
	string word;
	while (inFile >> word)
		words.push_back(word);
	cin.clear();

	//sort container
	sort(words.begin(), words.end());
	
	//erase same word
	words.erase(unique(words.begin(), words.end()), words.end());

	//count and put
	vector<string>::size_type wc = 0;
	greater_equal<string::size_type> greq;
	for (vector<string>::iterator iter = words.begin();
	iter != words.end(); ++iter) {
			if (greq(iter->size(), 10)) {
				cout << *iter << " ";
				++wc;
			}
	}

	cout << endl << wc << " " << make_plural(wc, "word", "s")
		<< " 10 characters or longer" << endl;

	return 0;
}
		
