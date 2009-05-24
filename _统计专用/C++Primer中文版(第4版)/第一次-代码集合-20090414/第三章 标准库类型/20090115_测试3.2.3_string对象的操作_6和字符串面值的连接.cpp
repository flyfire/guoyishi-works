#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1="hello";
	string s2("world");
	string s5=s1+","+"china";	//ok:tmp=s1+"," ,s5=tmp+"china".
	string s6 = "hello" + "," + s2;	//error:"hello"不能和","相加.

	return 0;
}
