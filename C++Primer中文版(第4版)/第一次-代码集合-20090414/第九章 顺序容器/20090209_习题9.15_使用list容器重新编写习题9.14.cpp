#include <iostream>
#include <list>
#include <string>
using namespace std;

int main()
{
	list<string> slst;
	string str;

	//得到String值
	cout << "Enter strings(Ctrl+Z to end):" << endl;
	while (cin >> str)
		slst.push_back(str);

	//输出String值
	for (list<string>::iterator iter = slst.begin(); iter != slst.end(); ++iter)
		cout << *iter << endl;

	return 0;
}