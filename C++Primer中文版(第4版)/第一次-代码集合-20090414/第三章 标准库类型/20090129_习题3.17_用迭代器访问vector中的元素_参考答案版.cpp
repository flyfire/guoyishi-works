//2009.01.29

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> ivec;
	int ival;

	//get vector
	cout << "Enter numbers(Ctrl+Z to end):" << endl;
	while(cin >> ival)
		ivec.push_back(ival);

	//vector.size==0?
	if(ivec.size()==0){
		cout << "No element?!" << endl;
		return -1;
	}
	cout << "Sum of each pair of adjacent elements in the vector:"
		<< endl;
	vector<int>::size_type cnt = 0;
	for(vector<int>::iterator iter = ivec.begin();iter < ivec.end()-1;iter = iter +2){
		cout << *iter + *(iter+1) << "\t";
		++cnt;
		if(cnt%6==0)
			cout << endl;
	}

	if(ivec.size() % 2 != 0)
		cout << endl
		<< "The last element is not been summed "
		<< "and its value is "
		<< *(ivec.end()-1)\
		<< endl;

	return 0;
}

