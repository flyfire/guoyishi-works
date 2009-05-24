#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> ivec;
	int ival;

	cout << "Enter numbers(Ctrl+Z to end):" << endl;
	while(cin >> ival)
		ivec.push_back(ival);

	if(ivec.size()==0){
		cout << "No element?!" << endl;
		return -1;
	}
	cout << "Sum of each pair of counterpart elements in the vector:"
		<< endl;
	vector<int>::size_type cnt=0;
	vector<int>::size_type first,last;
	for(first=0,last=ivec.size()-1;first<last;first++,last--){
		cout << ivec[first]+ivec[last] << "\t";
		++cnt;
		if((cnt+1)%6==0)
			cout << endl;
	}

	if(first==last)
		cout << endl
		<< "The center element is not been summmed "
		<< "and its value is "
		<<ivec[first] <<endl;

	return 0;
}