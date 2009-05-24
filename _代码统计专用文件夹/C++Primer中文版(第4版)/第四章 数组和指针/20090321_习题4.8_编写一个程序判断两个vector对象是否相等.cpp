#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int ival;
	vector<int> ivec1, ivec2;
	
	//get ivec1
	cout << "Enter some integers(Ctrl+Z to end) for ivec1:" << endl;
	while (cin >> ival) {
		ivec1.push_back(ival);
	}
	cin.clear();

	//get ivec2
	cout << "Enter some integers(Ctrl+Z to end) for ivec2:" << endl;
	while (cin >> ival) {
		ivec2.push_back(ival);
	}
	cin.clear();

	//compare ivec1.size() and ivec2.size() 
	if (ivec1.size() != ivec2.size()) {
		cout << "Array1 is not equal to array2" << endl;
		return 0;
	}

	//compare ivec1 and ivec2
	vector<int>::iterator iter1 = ivec1.begin(), iter2 = ivec2.begin();
	for (; iter1 != ivec1.end(); ++iter1, ++iter2) {
		if (*iter1 != *iter2) {
			break;
		}
	}

	if (iter1 == ivec1.end())
		cout << "ivec1 is equal to ivec2." << endl;
	else
		cout << "ivec1 is not equal to ivec2." << endl;


	return 0;
}
