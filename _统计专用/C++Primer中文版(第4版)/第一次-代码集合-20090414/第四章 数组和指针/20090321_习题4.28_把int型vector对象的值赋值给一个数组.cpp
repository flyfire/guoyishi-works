//20090321 remmber to delete the array what you create
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

	//wo also can use a Pointer!
	//like int *tp = ia;
	int *ia = new int[ivec.size()];
	size_t ix = 0;
	for (vector<int>::iterator iter = ivec.begin();
	iter != ivec.end(); ++iter, ++ix) {
		ia[ix] = *iter;
	}

	for (ix = 0; ix != ivec.size(); ++ix) {
		cout << ia[ix] << " ";
	}
	cout << endl;

	//delete is IMPORTENT!!!
	delete [] ia;

	return 0;
}