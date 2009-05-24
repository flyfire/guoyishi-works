#include <iostream>
#include <vector>
#include <list>
#include <algorithm>	//δ�õ�
using namespace std;

int main()
{
	int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};

	size_t ia_size = sizeof(ia) / sizeof(int);
	vector<int> ivec(ia, ia+ia_size);
	list<int> ilst(ia, ia+ia_size);

	//ɾ��list�����е�����ֵԪ��
	list<int>::iterator lit = ilst.begin();
	while (lit != ilst.end()) {
		if (*lit % 2 != 0)
			lit = ilst.erase(lit);
		else
			++lit;
	}

	//ɾ��vector�����е�ż��ֵԪ��
	vector<int>::iterator vit = ivec.begin();
	while (vit != ivec.end()) {
		if (*vit % 2 == 0)
			vit = ivec.erase(vit);
		else
			++vit;
	}

	//���list�����е�Ԫ��
	lit = ilst.begin();
	while (lit != ilst.end())
		cout << *lit++ << " ";
	cout << endl;

	//���vector�����е�Ԫ��
	vit = ivec.begin();
	while (vit != ivec.end())
		cout << *vit++ << " ";
	cout << endl;

	return 0;
}

