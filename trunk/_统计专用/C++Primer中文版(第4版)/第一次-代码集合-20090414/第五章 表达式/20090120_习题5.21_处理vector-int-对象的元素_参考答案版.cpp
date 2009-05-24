#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> ivec(20,1);

	for(vector<int>::iterator iter = ivec.begin();
		iter != ivec.end();++iter)
		*iter =(*iter%2 ? *iter * 2 : *iter);

	return 0;
}