#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> ivec1,ivec2;
	int ival;

	//Get the first vector
	cout << "Enter elements for the first vector(Ctrl+Z to end):" << endl;
	while(cin >> ival)
		ivec1.push_back(ival);

	//Get the second vector
	cin.clear();
	cout << "Enter elements for the second vector(Ctrl+Z to end):" << endl;
	while(cin >> ival)
		ivec2.push_back(ival);

	//Get the 
	vector<int>::size_type len1=ivec1.size(),len2=ivec2.size(),len;
	if(len1<=len2)
		len=len1;
	else
		len=len2;

	int flag = 1;
	for(vector<int>::size_type index = 0;index != len;++index)
	{
		if(ivec1[index] != ivec2[index])
			flag = 0;
	}

	if(flag)
		cout << "Yes!" << endl;
	else
		cout << "No!" << endl;

	return 0;
}




	