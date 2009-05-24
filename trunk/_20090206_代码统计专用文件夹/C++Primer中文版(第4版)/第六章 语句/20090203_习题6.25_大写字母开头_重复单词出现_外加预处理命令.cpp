#include <iostream>
#include <string>
#include <cctype>	//add this
using namespace std;

int main()
{
	string currWord,preWord;

	cout << "Enter Word(Ctrl+Z to end):";
	while(cin >> currWord){
		#ifndef NDEBUG
		cout << currWord << endl;
		#endif
		cout << endl << "Enter Word:";
		if(islower(currWord[0]))
			continue;
		if(currWord == preWord)
			break;
		else
			preWord = currWord;

	}
	
	if(currWord == preWord && !currWord.empty())
		cout << "What you want is \"" << currWord << "\"" << endl;
	else
		cout << "No same word" << endl;

	return 0;
}
