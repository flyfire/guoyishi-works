#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> ivec(10,20);
	for(vector<int>::iterator iter = ivec.begin();iter != ivec.end();++iter)
		*iter = (*iter)*2;

	return 0;
}