#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool isShorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size();
}

class BET_cls {
public:
	BET_cls(string::size_type len1, string::size_type len2)
	{
		if (len1 < len2) {
			minLength = len1;
			maxLength = len2;
		}
		else {
			minLength = len2;
			maxLength = len1;
		}
	}

	bool operator() (const string s)
	{
		return s.size() >= minLength && s.size() <= maxLength;
	}
private:
	string::size_type minLength;
	string::size_type maxLength;
};

class GT_cls {
public:
	GT_cls(size_t val = 0): bound(val) {}
	bool operator() (const string &s)
	{
		return s.size() >= bound;
	}
private:
	string::size_type bound;
};

string make_plural(size_t ctr, const string &word, const string &ending)
{
	return (ctr == 1) ? word : word + ending;
}

int main()
{
	string fileName;
	cout << "Enter file name:" << endl;
	cin >> fileName;
	ifstream inFile(fileName.c_str());
	if (!inFile) {
		cerr << "Can not open file!" << endl;
		return EXIT_FAILURE;
	}

	vector<string> words;
	string word;
	while (inFile >> word)
		words.push_back(word);

	sort(words.begin(), words.end());
	
	words.erase(unique(words.begin(), words.end()), words.end());

	vector<string>::size_type wc = count_if (words.begin(), words.end(), BET_cls(1,9));
	cout << wc << " " << make_plural(wc, "word", "s")
		<< " are of sizes 1 through 9 inclusive" << endl;
	wc = count_if (words.begin(), words.end(), GT_cls(10));
	cout << wc << " " << make_plural(wc, "word", "s")
		<< " 10 characters or longer" << endl;

	return 0;
}