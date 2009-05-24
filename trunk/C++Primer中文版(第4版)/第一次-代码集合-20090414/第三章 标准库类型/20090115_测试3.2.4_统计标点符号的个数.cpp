#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s("Hello World!!!");
	string::size_type punct_cnt =0;
	for(string::size_type index=0;index!=s.size();++index)
		if(ispunct(s[index]))
			++punct_cnt;
	cout << punct_cnt
		<< " punctuation characters in " << s << endl;

	//upper to lower
	for(index=0;index)
	return 0;
}