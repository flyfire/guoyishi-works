#include <iostream>
#include <vector>
using namespace std;

//�ڵ�������ǵķ�Χ��Ѱ�Ҹ�����int����ֵ
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

	//�õ�ҪѰ�ҵ���ֵ
	cout << "Enter a integer:" << endl;
	int ival;
	cin >> ival;

	//����findInt��������ival
	vector<int>::iterator it;
	it = findInt (ivec.begin(), ivec.end(), ival);
	if (it != ivec.end())	//�ҵ�
		cout << ival << " is a element of the vector." << endl;
	else
		cout << ival << " isn't a element of the vector." << endl;

	return 0;
}