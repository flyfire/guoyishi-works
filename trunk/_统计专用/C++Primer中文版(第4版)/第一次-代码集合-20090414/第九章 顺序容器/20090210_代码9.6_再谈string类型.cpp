#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s("Hiya!");
	string::iterator iter = s.begin();
	while (iter != s.end())
		cout << *iter++ << endl;

	return 0;
}