#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str,result_str;
	bool have_punct = false;
	char ch;

	cout << "Enter string:" << endl;
	getline(cin,str);	//用了getline函数来得到一行字符串,其中可能包含空格.
	for(string::size_type index = 0;index != str.size();index++){
		ch = str[index];
		if(ispunct(ch))
			have_punct = true;
		else
			result_str += ch;
	}

	if(have_punct)
		cout << "Result:" << endl << result_str << endl;
	else{
		cout << "No punctuation character in the string!" << endl;
		return -1;
	}

	return 0;
}