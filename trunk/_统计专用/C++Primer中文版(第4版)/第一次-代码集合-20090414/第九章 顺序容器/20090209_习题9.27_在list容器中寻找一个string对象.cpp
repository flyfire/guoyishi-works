#include <iostream>
#include <list>
#include <string>
using namespace std;

int main()
{
	list<string> slst;
	string str;

	//读入list对象
	cout << "Enter some strings(Ctrl+Z to end):" << endl;
	while (cin >> str)
		slst.push_back(str);
	cin.clear();

	//得到那个特殊的string对象
	cout << "Enter a string that you want wo search: " << endl;
	cin >> str;

	//查找那个特殊的string对象并删除
	size_t cnt = 0;
	list<string>::iterator lit = slst.begin();
	while (lit != slst.end()) {
		if (*lit == str) {
			lit = slst.erase(lit);
			++cnt;
		}
		else
			++lit;
	}

	//输出删除后的结果
	lit = slst.begin();
	if (cnt) {
		cout << str << " appears " << cnt << " times." << endl;
		while (lit != slst.end())
			cout << *lit++ << " ";
		cout << endl;
	}
	else {
		cout << str << " doesn't appears!" << endl;
		while (lit != slst.end())
			cout << *lit++ << " ";
		cout << endl;
	}

	return 0;
}



