#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string line1 = "We were her pride of 10 she named us:";
	string line2 = "Benjamin, Phoenix, the Prodigal";
	string line3 = "and perspicacious pacific Suzanne";

	string sentence = line1 + ' ' + line2 + ' ' + line3;

	string separators(" \t:,\v\r\n\f");
	string word;
	string::size_type maxLen, minLen, wordLen, count = 0;
	vector<string> longestWords, shortestWords;
	string::size_type startPos = 0, endPos = 0;

	while ((startPos = sentence.find_first_not_of(separators, endPos)) != string::npos) {
		++count;

		endPos = sentence.find_first_of(separators, startPos);

		if (endPos == string::npos) {
			//最后一个单词
			wordLen = sentence.size() - startPos;
		}
		else {
			wordLen = endPos - startPos;
		}

		word.assign(sentence.begin() + startPos, sentence.begin() + startPos + wordLen);	//获取单词

		//设置下次查找的起始位置
		startPos = sentence.find_first_not_of(separators, endPos);

		if (count == 1) {	//查找的是第一个单词
			maxLen = minLen = wordLen;
			longestWords.push_back(word);
			shortestWords.push_back(word);
		}
		else {
			if (wordLen > maxLen) {	//当前单词比目前最长单词更长
				maxLen = wordLen;
				longestWords.clear();	//清空存放最长单词的容器
				longestWords.push_back(word);
			}
			else if (wordLen == maxLen)	//当前单词与最长单词一样长
				longestWords.push_back(word);

			if (wordLen < minLen) {	//当前单词比目前最短单词更短
				minLen = wordLen;
				shortestWords.clear();	//清空存放最短单词的容器
				shortestWords.push_back(word);
			}
			else if (wordLen == minLen)	//当前单词与最短单词一样短
				shortestWords.push_back(word);
		}
	}

	//输出单词数目
	cout << "word amount: " << count << endl;
	vector<string>::iterator iter;

	//输出最长单词
	cout << "longest word(s):" << endl;
	iter = longestWords.begin();
	while (iter != longestWords.end())
		cout << *iter++ << endl;

	//输出最短单词
	cout << "shortest word(s):" << endl;
	iter = shortestWords.begin();
	while (iter != shortestWords.end())
		cout << *iter++ << endl;

	return 0;
}