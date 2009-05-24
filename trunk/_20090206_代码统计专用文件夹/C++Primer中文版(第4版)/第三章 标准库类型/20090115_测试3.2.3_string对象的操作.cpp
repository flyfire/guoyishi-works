#include <iostream>
#include <string>
using namespace std;

int main()
{
	//初始化这几个字符串
	string s1,s2="1234567890",s4;
	string s3("abc");	//直接初始化
	
	//输出这几个字符串
	cout << "\ns1: " << s1
		<< "\ns2: " << s2
		<< "\ns3: " << s3
		<< "\ns4: " << s4 << endl;

	//string.empty的应用
	cout << "Is \"s1\" empty? "
		<< s1.empty() << endl;

	//string.size的应用
	cout << "The size of \"s1\" is "
		<< s1.size() << endl;

	//string[n]的应用
	cout << "No.5(number from 0) of " << s2 << " is "
		<<s2[5] << endl;

	//s2+s3的应用
	s4=s2+s3;
	cout << s2 << " + " << s3 << " is " 
		<< s4 << endl;

	//s1=s2的应用
	s1=s2;
	cout << "s1=s2:\t" << "s1:" << s1
		<< "\ts2:" << s2 << endl;

	//s1==s2的应用
	if(s1==s2)
		cout << s1 << " == " << s2 << endl;

	//关于string::size_type类型
	int val;
	val=s1.size();
	cout << "val=" << val << endl;	//当size大于32767时,int型就不能接收,所以最好不要用int型来接收.

	return 0;
}