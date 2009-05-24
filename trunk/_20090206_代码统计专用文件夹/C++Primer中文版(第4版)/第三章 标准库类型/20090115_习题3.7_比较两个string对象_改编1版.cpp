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
	else
	{
		if(s1>s2)
			cout << "s1: " << s1 << " > " << "s2: " << s2 << endl;
		else
			cout << "s2: " << s2 << " > " << "s1: " << s1 << endl;
	}
	int len1=s1.size();
	int len2=s2.size();
	if(len1==len2)
		cout << "s1'size " << s1.size() << " == " << "s2'size " << s2.size() << endl; 
	else
	{
		if(len1>len2)
			cout << "s1'size: " << s1.size() << " > " << "s2'size: " << s2.size() << endl;
		else
			cout << "s2'size: " << s2.size() << " > " << "s1'size: " << s1.size() << endl;
	}

	return 0;
}