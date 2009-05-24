#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
	set<string> excluded;
	string exWord;
	
	cout << "Enter excluded words(Ctrl+Z to end):" << endl;
	while (cin >>exWord)
		excluded.insert(exWord);
	cin.clear();

	cout << "Enter words(Ctrl+Z to end):" << endl;
	string word;
	/*
	********************¼òµ¥°æ±¾**********************
	*/
	while (cin >> word) {
		if (!excluded.count(word))
			word.resize(word.size()-1);
		cout << word << endl;
	}
	/*
	********************¸´ÔÓ°æ±¾**********************
	while (cin >> word) {
		if (excluded.count(word))
			cout << word << endl;
		else {
			word.resize(word.size()-1);
			cout << word << endl;
		}
	}
	**************************************************
	*/

	return 0;
}