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

	//����int���󲢴洢��list������
	cout << "Enter some integers(Ctrl+Z to end):" << endl;
	while (cin >> ival)
		ilst.push_back(ival);

	//����list����deque������ȥ
	for (list<int>::iterator iter = ilst.begin(); iter != ilst.end(); ++iter) {
		if (*iter % 2 == 0)
			evenDq.push_back(*iter);
		else
			oddDq.push_back(*iter);
	}

	//�������deque����
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