#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	vector<string> svec;
	string str;

	cout << "Enter strings(Ctrl+Z to end):" << endl;
	while (cin >> str)
		svec.push_back(str);

	//添加一个if语句,判断vector容器是否含有元素:
	if(!svec.empty()) {
		cout << "The first element is:" << endl;
		cout << "svec[0]:" << svec[0] << endl;
		cout << "svec.front():" << svec.front() << endl;
		cout << "*svec.begin():" << *svec.begin() << endl;
	}
	else {
		cout << "No element?!" << endl;
		return -1;
	}
	
	return 0;
}

