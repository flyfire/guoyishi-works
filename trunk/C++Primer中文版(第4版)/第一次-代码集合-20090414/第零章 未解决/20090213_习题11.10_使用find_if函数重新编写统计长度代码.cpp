#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool isShorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size();
}

bool GT6(const string &s)
{
	return s.size() >= 6;
}

string make_plural(size_t ctr, const string word, const string ending)
{
	return (ctr == 1) ? word : word + ending;
}

int main(int argc, char **argv)
{
	if (argc < 2) {
		cerr << "No input file!" << endl;
		return EXIT_FAILURE;
	}
	ifsream inFile;
	inFile.open(argv[1]);
	if (!inFile) {
		cerr << "Can not open input file!" << endl;
		return EXIT_FAILURE;
	}

	vector<string> words;
	string word;
	while (inFile >> word)
		words.push_back(word);

	sort(words.begin(), words.end());

	words.erase(unique(words.begin(), words.end()), words.end());

	stable_sort(words.begin(), words.end(), isShorter);

	vector<string>::iterator iter = words.begin();
	vector<string>::size_type wc = 0;
	while ((iter = find_if(iter, words.end(), GT6)) != words.end()) {
		++wc;
		++iter;
	}

	cout << wc << " " << make_plural(wc, "word", "s")
		<< " 6 characters or longer" << endl;

	cout << "unique words:" << endl;
	for (iter = words.begin(), iter != words.end(), ++iter)
		cout << *iter << " ";
	cout << endl;

	return 0;
}