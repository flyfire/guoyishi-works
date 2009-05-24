//20090329 INSERTION SORT(A)
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, ival;
	vector<int> ivec;
	
	//get values
	cout << "Enter value number:";
	cin >> n;
	int k = n;
	while (k--) {
		cin >> ival;
		ivec.push_back(ival);
	}

	//print ivec frist time
	for (vector<int>::iterator iter = ivec.begin();
	iter != ivec.end(); ++iter)
		cout << *iter << " ";
	cout << endl;

	//insertion sort #a
	int i, j;
	for (j = 1; j < n; ++j) {
		int key = ivec[j];
		i = j - 1;
		while (i >= 0 && ivec[i] > key) {
			ivec[i+1] = ivec[i];
			--i;
		}
		ivec[i+1] = key;

		//print ivec each step
		for (vector<int>::iterator iter = ivec.begin();
		iter != ivec.end(); ++iter)
			cout << *iter << " ";
		cout << endl;
		//print underline
		for (int under = 0; under < n; ++under) {
			if (under == j)
				cout << "- ";
			else
				cout << "  ";
		}
		cout << endl;
	}

	return 0;
}