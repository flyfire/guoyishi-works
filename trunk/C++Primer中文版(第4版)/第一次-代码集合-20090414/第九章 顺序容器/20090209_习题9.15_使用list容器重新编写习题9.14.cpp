#include <iostream>
#include <list>
#include <string>
using namespace std;

int main()
{
	list<string> slst;
	string str;

	//�õ�Stringֵ
	cout << "Enter strings(Ctrl+Z to end):" << endl;
	while (cin >> str)
		slst.push_back(str);

	//���Stringֵ
	for (list<string>::iterator iter = slst.begin(); iter != slst.end(); ++iter)
		cout << *iter << endl;

	return 0;
}