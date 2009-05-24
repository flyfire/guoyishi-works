#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<char> cvec;
	char ch;

	cout << "Enter some char " << endl;
	while (cin >> ch && ch !='#')
		cvec.push_back(ch);
	cin.clear();

	vector<char>::iterator iter = cvec.end();
	--iter;	//iter指向的是超出末端下一个元素
	while (iter != cvec.begin())
		cout << *iter-- << " ";
	cout << endl;

	return 0;
}
