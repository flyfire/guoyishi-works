#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str1,str2,str3;
	do{
		cout << "Enter two strings" << endl;
		cin >> str1 >> str2;
		if(str1 < str2)
			cout << "str1 < str2" << endl;
		else if(str1 == str2)
			cout << "str1 = str2" << endl;
		else
			cout << "str1 > str2" << endl;

		cout << "Continue?(Yes/No)" << endl;
		cin >> str3;
	}while(str3[0] != 'n'&&str3[0] != 'N');

	return 0;
}