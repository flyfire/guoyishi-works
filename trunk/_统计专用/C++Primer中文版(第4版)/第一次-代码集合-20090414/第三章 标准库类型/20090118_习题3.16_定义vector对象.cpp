#include <iostream>
#include <vector>
using namespace std;

int main()
{
	//1
	vector <int> ivec1(10,42);

	//2
	vector<int> ivec2(ivec1);

	//3
	vector<int> ivec3;
	for(vector<int>::size_type i=0;i!=10;i++)
		ivec3.push_back(42);

	//4
	vector<int> ivec4;
	for(vector<int>::size_type ix = 0;ix != 10;ix++)
		ivec4[ix]=42;

	//5
	vector<int> ivec5;
	for(vector<int>::iterator iter = ivec5.begin();iter != ivec5.end(); iter++)
		*iter = 42;

	//6
	vector<int> ivec6;
	vector<int>::iterator iter2 = ivec6.end();
	for(int i = 0;i != 10;++i){
		ivec6.insert(iter2,42);
		iter2 = ivec6.end();
	}

	return 0;

}
