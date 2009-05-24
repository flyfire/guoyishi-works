#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str,result_str;
	char ch;

	cout << "Enter string:" << endl;
	getline(cin,str);	//用了getline函数来得到一行字符串,其中可能包含空格.
	for(string::size_type index = 0;index != str.size();index++)
	{
		ch = str[index];
		if(!ispunct(ch))
		{
			result_str += ch;;
		}
	}

	cout << "Result:" << endl << result_str << endl;

	return 0;
}