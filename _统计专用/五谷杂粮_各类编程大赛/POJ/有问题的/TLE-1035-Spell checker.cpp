//20090411 Spell checker
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//?deleting of one letter from the word; 
bool deleting(string word, string dic)
{
	string temp, temp2;
	int len = dic.size();
	int i = 0;
	while (i != len) {
		temp = dic;
		temp2 = temp.erase(i, 1);
		if (word == temp2)
			return true;
		++i;
	}

	return false;
}

//?replacing of one letter in the word with an arbitrary letter; 
bool replacing(string word, string dic)
{
	if (word.size() != dic.size())
		return false;
	int len = dic.size();
	int i = 0, cnt = 0;
	while (i != len) {
		if (word[i] != dic[i])
			++cnt;
		if (cnt == 2)
			return false;
		++i;
	}
	return true;
}

//?inserting of one arbitrary letter into the word. 
bool inserting(string word, string dic)
{
	//use the deleting function again
	if (deleting(dic, word))
		return true;
	return false;
}

//check the word and the dictionary word
void check(string word, string dic)
{
	if (deleting(word, dic)) {
		cout << " " << dic;
		//cout << endl << "deleting" << endl;	/////////////////////////////////
		return;
	}
	if (replacing(word, dic)) {
		cout << " " << dic;
		//cout << endl << "replacing" << endl;	/////////////////////////////////
		return;
	}
	if (inserting(word, dic)) {
		cout << " " << dic;
		//cout << endl << "inserting" << endl;	/////////////////////////////////
		return;
	}

	return;
}


int main()
{
	vector<string> dictionary;
	vector<string> words;

	string word;
	//get the dictinary
	while (cin >> word && word != "#") {
		dictionary.push_back(word);
	}

	//get the be checked words
	while (cin >> word && word != "#") {
		words.push_back(word);
	}

	vector<string>::const_iterator dic_iter;
	vector<string>::const_iterator words_iter = words.begin();
	while (words_iter != words.end()) {

		dic_iter = dictionary.begin();

		bool flag = false;

		while (dic_iter != dictionary.end()) {
			if (*words_iter == *dic_iter) {
				cout << *words_iter << " is correct";
				flag = true;
				break;
			}
			++dic_iter;
		}
		//if equal continue again
		if (flag) {
			cout << endl;
			++words_iter;	//add to next
			continue;
		}

		dic_iter = dictionary.begin();

		cout << *words_iter << ":";
		while (dic_iter != dictionary.end()) {
			check(*words_iter, *dic_iter);
			++dic_iter;	//add to next
		}
		cout << endl;
		++words_iter;	//add to next
	}

	return 0;
}