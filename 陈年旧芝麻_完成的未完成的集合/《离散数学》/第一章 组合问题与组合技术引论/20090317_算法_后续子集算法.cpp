#include <iostream>
#include <vector>
using namespace std;

int main()
{
	char ch;
	int n = 0, k;
	vector<char> cvec;

	//get n
	cout << "Enter n :";
	cin >> n;

	//get the "string"
	k = n;
	cout << "Enter the \"string\":" << endl;
	while (k--) {
		cin >> ch;
		cvec.push_back(ch);
	}

	//search the "0"
	vector<char>::reverse_iterator r_iter =cvec.rbegin();
	while (*r_iter == '1') {
		++r_iter;
	}

	if (r_iter != cvec.rend()) {
		*r_iter = '1';	//change the first "0" to "1"
		--r_iter;	//to the next of the "0"
		if (r_iter != cvec.rbegin())
			while (r_iter != cvec.rbegin() - 1) { //put "0" to all next to the "0"
				*r_iter = '0';
				--r_iter;
			}

		cout << "Next:" << endl;
	}
	else
		cout << "all is \"1\"" << endl;


	//print the "string"
	for (vector<char>::iterator iter = cvec.begin(); iter != cvec.end(); ++iter) {
		cout << *iter;
	}
	cout << endl;

	return 0;
}