#include <iostream>
#include <string>
using namespace std;

int main()
{
	string currWord,preWord;

	cout << "Enter Word(Ctrl+Z to end):";
	while(cin >> currWord){
		cout << endl;
		if(currWord == preWord)
			break;
		else
			preWord = currWord;
		cout << "Enter Word:";
	}
	
	if(currWord == preWord && !currWord.empty())
		cout << "What you want is \"" << currWord << "\"" << endl;
	else
		cout << "No same word" << endl;

	return 0;
}
