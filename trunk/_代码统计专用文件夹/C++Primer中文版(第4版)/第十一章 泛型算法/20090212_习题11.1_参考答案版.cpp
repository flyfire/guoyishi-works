#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int ival,searchValue;
	vector<int> ivec;

	cout << "Enter some integers(Ctrl+Z to end):" << endl;
	while (cin >> ival)
		ivec.push_back(ival);

	cin.clear();

	cout << "Enter an integer you want wo search:" << endl;
	cin >> searchValue;

	cout << count(ivec.begin(), ivec.end(), searchValue)
		<< " elements in the vector have value "
		<< searchValue << endl;

	return 0;
}