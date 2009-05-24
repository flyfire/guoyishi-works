#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1,s2;

	cin >> s1 >> s2;
	cout << s1 << " " << s2 << endl;
	if(s1==s2)
		cout << "\ns1 == s2\n";
	else if(s1>s2)
		cout << "s1: " << s1 << " > " << "s2: " << s2 << endl;
	else if(s2>s1)
		cout << "s2: " << s2 << " > " << "s1: " << s1 << endl;

	return 0;
}