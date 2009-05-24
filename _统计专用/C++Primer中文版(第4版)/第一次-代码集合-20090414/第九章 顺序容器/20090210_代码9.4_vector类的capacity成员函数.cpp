#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> ivec;

	cout << "ivec: size: " << ivec.size()
		<< "\tcapacity: " << ivec.capacity() << endl;
	
	//���Ԫ��
	for (vector<int>::size_type ix = 0; ix != 24; ++ix) {
		ivec.push_back(ix);
	}

	cout << "ivec: size: " << ivec.size()
		<< "\tcapacity: " << ivec.capacity() << endl;

	//ʹ��reserve()���Ԥ���ռ�
	ivec.reserve(50);

	cout << "ivec: size: " << ivec.size()
		<< "\tcapacity: " << ivec.capacity() << endl;

	//��Ԥ���ռ�ʹ����
	while (ivec.size() != ivec.capacity())
		ivec.push_back(0);

	cout << "ivec: size: " << ivec.size()
		<< "\tcapacity: " << ivec.capacity() << endl;

	//����µ�Ԫ��
	ivec.push_back(0);

	cout << "ivec: size: " << ivec.size()
		<< "\tcapacity: " << ivec.capacity() << endl;

	//����reserve���÷�
	cout << "ivec: size: " << ivec.size()
		<< "\tcapacity: " << ivec.capacity()
		<< "\treserve(50): " << ivec.reserve(50) << endl;	//Wrong!


	return 0;
}