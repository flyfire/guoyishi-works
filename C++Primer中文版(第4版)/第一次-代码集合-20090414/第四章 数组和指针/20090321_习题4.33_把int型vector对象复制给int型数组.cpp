//20090321 Care of DELETE
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int ival;
	vector<int> ivec;

	cout << "Enter some integers(Ctrl+Z to end):" << endl;
	while (cin >> ival) {
		ivec.push_back(ival);
	}
	cin.clear();

	int *parr = new int[ivec.size()];

	size_t ix;
	vector<int>::iterator iter = ivec.begin();
	for (ix = 0; ix != ivec.size(); ++ix) {
		parr[ix] = *iter++;
		cout << parr[ix] << " ";
		if ((ix + 1) % 10 == 0)
			cout << endl;
	}
	cout << endl;

	delete [] parr;	//IMPORTANT

	return 0;
}
