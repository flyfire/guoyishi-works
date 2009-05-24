#include <iostream>
#include <list>
#include <string>
using namespace std;

int main()
{
	list<string> slst;
	string str;

	//����list����
	cout << "Enter some strings(Ctrl+Z to end):" << endl;
	while (cin >> str)
		slst.push_back(str);
	cin.clear();

	//�õ��Ǹ������string����
	cout << "Enter a string that you want wo search: " << endl;
	cin >> str;

	//�����Ǹ������string����ɾ��
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

	//���ɾ����Ľ��
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



