#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s("hello world");
	string s2 = s.substr(6, 5);
	string s3 = s.substr(6);

	cout << s << endl << s2 << endl << s3 << endl;

	return 0;
}