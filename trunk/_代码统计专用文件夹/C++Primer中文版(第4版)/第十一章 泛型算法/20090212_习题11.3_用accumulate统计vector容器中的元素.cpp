#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main()
{
	vector<int> ivec;
	int ival;

	cout << "Enter some integers(Ctrl+Z to end):" << endl;
	while (cin >> ival)
		ivec.push_back(ival);

	size_t cnt = accumulate(ivec.begin(), ivec.end(), 0);

	cout << "sum: " << cnt << endl;

	return 0;
}
