#include <iostream>
#include <string>
using namespace std;

int main()
{
	//��ʼ���⼸���ַ���
	string s1,s2="1234567890",s4;
	string s3("abc");	//ֱ�ӳ�ʼ��
	
	//����⼸���ַ���
	cout << "\ns1: " << s1
		<< "\ns2: " << s2
		<< "\ns3: " << s3
		<< "\ns4: " << s4 << endl;

	//string.empty��Ӧ��
	cout << "Is \"s1\" empty? "
		<< s1.empty() << endl;

	//string.size��Ӧ��
	cout << "The size of \"s1\" is "
		<< s1.size() << endl;

	//string[n]��Ӧ��
	cout << "No.5(number from 0) of " << s2 << " is "
		<<s2[5] << endl;

	//s2+s3��Ӧ��
	s4=s2+s3;
	cout << s2 << " + " << s3 << " is " 
		<< s4 << endl;

	//s1=s2��Ӧ��
	s1=s2;
	cout << "s1=s2:\t" << "s1:" << s1
		<< "\ts2:" << s2 << endl;

	//s1==s2��Ӧ��
	if(s1==s2)
		cout << s1 << " == " << s2 << endl;

	//����string::size_type����
	int val;
	val=s1.size();
	cout << "val=" << val << endl;	//��size����32767ʱ,int�;Ͳ��ܽ���,������ò�Ҫ��int��������.

	return 0;
}