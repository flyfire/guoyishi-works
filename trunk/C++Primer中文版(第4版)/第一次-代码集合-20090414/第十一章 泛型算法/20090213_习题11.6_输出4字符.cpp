#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

typedef vector<string>::iterator vs_it;

bool isShorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size();
}

bool GT4(const string &s)
{
	return s.size() >= 4;
}

string make_plural(size_t ctr, const string &word, const string &ending)
{
	return (ctr == 1) ? word : word + ending;
}

inline void print(vs_it beg, vs_it end)
{
	static int cnt = 1;
	cout << "#" << cnt++ << ": ";
	vs_it iter = beg;
	while (iter != end)
		cout << *iter++ << " ";
	cout << endl;
}

int main()
{
	vector<string> words;
	string word;

	//#1
	cout << "Enter some words(Ctrl+Z to end):" << endl;
	while (cin >> word)
		words.push_back(word);

	cin.clear();

	print(words.begin(), words.end());

	//#2
	sort(words.begin(), words.end());
	print(words.begin(), words.end());

	//#3
	vs_it end_unique =
		unique(words.begin(), words.end());
	print(words.begin(), words.end());

	//#4
	words.erase(end_unique, words.end());
	print(words.begin(), words.end());

	//#5
	stable_sort(words.begin(), words.end(), isShorter);
	print(words.begin(),words.end());

	//#6
	vector<string>::size_type wc =
		count_if(words.begin(), words.end(), GT4);
	cout << wc << " " << make_plural(wc, "word", "s")
		<< "4 characters or longer" << endl;
	print(words.begin(),words.end());

	return 0;
}
