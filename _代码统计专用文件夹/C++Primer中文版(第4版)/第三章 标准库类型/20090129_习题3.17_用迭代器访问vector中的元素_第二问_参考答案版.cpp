//2009.01.29

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> ivec;
	int ival;

	//
	cout << "Enter numbers(Ctrl+Z to end):" << endl;
	while(cin >> ival)
		ivec.push_back(ival);

	//
	if(ivec.size()==0){
		cout << "No element?!" << endl;
		return -1;
	}
	cout << "Sum of each pair of counterpart element in the vector:" << endl;
	vector<int>::size_type cnt =0;
	vector<int>::iterator iter1 = ivec.begin(),iter2=ivec.end()-1;
	for(;iter1 < iter2;++iter1,--iter2){
		cout << *iter1 + *iter2 << "\t";
		++cnt;
		if(cnt % 6 ==0)
			cout << endl;
	}
	if(ivec.size()%2!=0)	// if(iter1 == iter2)
		cout << endl
			<< "The center element is not been summed "
			<< "and its value is "
			<< *(ivec.end()-1) << endl;

	return 0;
}