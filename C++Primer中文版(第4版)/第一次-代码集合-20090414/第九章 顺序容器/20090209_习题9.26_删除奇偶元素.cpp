#include <iostream>
#include <vector>
#include <list>
#include <algorithm>	//未用到
using namespace std;

int main()
{
	int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};

	size_t ia_size = sizeof(ia) / sizeof(int);
	vector<int> ivec(ia, ia+ia_size);
	list<int> ilst(ia, ia+ia_size);

	//删除list容器中的奇数值元素
	list<int>::iterator lit = ilst.begin();
	while (lit != ilst.end()) {
		if (*lit % 2 != 0)
			lit = ilst.erase(lit);
		else
			++lit;
	}

	//删除vector容器中的偶数值元素
	vector<int>::iterator vit = ivec.begin();
	while (vit != ivec.end()) {
		if (*vit % 2 == 0)
			vit = ivec.erase(vit);
		else
			++vit;
	}

	//输出list容器中的元素
	lit = ilst.begin();
	while (lit != ilst.end())
		cout << *lit++ << " ";
	cout << endl;

	//输出vector容器中的元素
	vit = ivec.begin();
	while (vit != ivec.end())
		cout << *vit++ << " ";
	cout << endl;

	return 0;
}

