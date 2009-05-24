#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> ivec(10,20);
	for(vector<int>::iterator iter = ivec.begin();iter != ivec.end();++iter){
		cout << *iter << "\t";
		*iter = (*iter)*2;
		cout << *iter << endl;
	}

	return 0;
}