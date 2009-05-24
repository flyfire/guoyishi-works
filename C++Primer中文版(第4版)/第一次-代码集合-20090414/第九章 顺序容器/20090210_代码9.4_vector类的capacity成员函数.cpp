#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> ivec;

	cout << "ivec: size: " << ivec.size()
		<< "\tcapacity: " << ivec.capacity() << endl;
	
	//添加元素
	for (vector<int>::size_type ix = 0; ix != 24; ++ix) {
		ivec.push_back(ix);
	}

	cout << "ivec: size: " << ivec.size()
		<< "\tcapacity: " << ivec.capacity() << endl;

	//使用reserve()提高预留空间
	ivec.reserve(50);

	cout << "ivec: size: " << ivec.size()
		<< "\tcapacity: " << ivec.capacity() << endl;

	//将预留空间使用完
	while (ivec.size() != ivec.capacity())
		ivec.push_back(0);

	cout << "ivec: size: " << ivec.size()
		<< "\tcapacity: " << ivec.capacity() << endl;

	//添加新的元素
	ivec.push_back(0);

	cout << "ivec: size: " << ivec.size()
		<< "\tcapacity: " << ivec.capacity() << endl;

	//关于reserve的用法
	cout << "ivec: size: " << ivec.size()
		<< "\tcapacity: " << ivec.capacity()
		<< "\treserve(50): " << ivec.reserve(50) << endl;	//Wrong!


	return 0;
}