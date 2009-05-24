#include <iostream>
#include <vector>
using namespace std;

//在迭代器标记的范围内寻找给定的int型数值
vector<int>::iterator findInt (vector<int>::iterator beg, vector<int>::iterator end, int ival)
{
	while (beg != end)
		if (*beg == ival)
			break;
		else
			++beg;
	return beg;
}

int main()
{
	int ia[] = {0, 1, 2, 3, 4, 5, 6};
	vector<int> ivec(ia, ia+7);

	//得到要寻找的数值
	cout << "Enter a integer:" << endl;
	int ival;
	cin >> ival;

	//调用findInt函数查找ival
	vector<int>::iterator it;
	it = findInt (ivec.begin(), ivec.end(), ival);
	if (it != ivec.end())	//找到
		cout << ival << " is a element of the vector." << endl;
	else
		cout << ival << " isn't a element of the vector." << endl;

	return 0;
}