#include <iostream>
#include <list>
#include <deque>
#include <string>
using namespace std;

int main()
{
	list<int> ilst;
	deque<int> evenDq, oddDq;
	int ival;

	//读入int对象并存储在list对象中
	cout << "Enter some integers(Ctrl+Z to end):" << endl;
	while (cin >> ival)
		ilst.push_back(ival);

	//复制list对象到deque对象中去
	for (list<int>::iterator iter = ilst.begin(); iter != ilst.end(); ++iter) {
		if (*iter % 2 == 0)
			evenDq.push_back(*iter);
		else
			oddDq.push_back(*iter);
	}

	//输出两个deque对象
	deque<int>::iterator it;

	it = evenDq.begin();
	cout << "even deque:" << endl;
	while (it != evenDq.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;

	it = oddDq.begin();
	cout << "odd deque:" << endl;
	while (it != oddDq.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;

	return 0;
}