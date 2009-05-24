#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int value;	//MAX

	cout << "Enter a number what is the \"Value\"" << endl;
	cin >> value;

	//1 and what less than 1 is wrong number
	if (value <= 1) {
		cout << "Wrong input value!" << endl;
		return EXIT_FAILURE;
	}

	//let container vector hold "numbers"
	vector<int> ivec;

	//get original "numbers"
	for (int i = 2; i <= value; ++i) {
		ivec.push_back(i);
		cout << i << " ";
	}

	int p = 2;
	int k;
	while (p * p <= value) {
		k = p * p;
		while (k <= value) {
			cout << "TEST #3 k = " << k << " p = " << p << endl;
			//find and erase the "composite numbers"
			if (find(ivec.begin(), ivec.end(), k) != ivec.end())
				ivec.erase(find(ivec.begin(),ivec.end(),k));

			k += p;
			cout << "TEST #1 k = " << k << " p = " << p << endl;
		}
		++p;

		cout << "TEST #2 p = " << p << endl;
	}

	//print the "prime numbers"
	cout << "\n\n\nPRIME NUMBERS:" << endl;
	vector<int>::iterator iter = ivec.begin();
	for (int cnt =1; iter != ivec.end(); ++iter) {
		cout << *iter << "\t";
		if (cnt++ % 10 == 0)
			cout << endl;
	}
	cout << endl;

	return 0;
}