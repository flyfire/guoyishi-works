#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str,result_str;
	char ch;

	cout << "Enter string:" << endl;
	getline(cin,str);	//����getline�������õ�һ���ַ���,���п��ܰ����ո�.
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