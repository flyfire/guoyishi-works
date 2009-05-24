#include <iostream>
#include <algorithm>
#include <vector>
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

string make_plural(size_t ctr, const string &word, const string &ending)
{
	return (ctr == 1) ? word : word + ending;
}

int main()
{
	vector<string> words;
	string word;

	cout << "Enter some words(Ctrl+Z to end):" << endl;
	while (cin >> word)
		words.push_back(word);

	cin.clear();

	sort(words.begin(), words.end());
	vector<string>::iterator end_unique =
		unique(words.begin(), words.end());
	words.erase(end_unique, words.end());

	stable_sort(words.begin(), words.end(), isShorter);
	
	vector<string>::size_type wc =
		count_if(words.begin(), words.end(), GT6);
	cout << wc << " " << make_plural(wc, "word", "s")
		<< " 6 characters or longer" << endl;

	for (vector<string>::iterator iter = words.begin();
	iter != words.end(); ++iter) {
		cout << *iter << " ";
	}
	cout << endl;

	return 0;
}