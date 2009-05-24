#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str("some string");
	for(string::size_type ix=0;ix!=str.size();++ix)
		cout << str[ix] << endl;

	//How about "int"
	for(int i=0;i!=str.size();++i)
		cout << str[i] << endl;

	return 0;
}
