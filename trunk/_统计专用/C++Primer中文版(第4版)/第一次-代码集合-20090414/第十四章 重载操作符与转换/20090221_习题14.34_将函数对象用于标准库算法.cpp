#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class EQ_cls {
public:
	EQ_cls(int val = 0): spValue(val) {}
	bool operator() (const int &ival)
	{
		return ival == spValue;
	}
private:
	int spValue;
};

int main()
{
	vector<int> ivec;
	int ival;

	cout << "Enter numbers(Ctrl+Z to end):" << endl;
	while (cin >> ival)
		ivec.push_back(ival);
	cin.clear();

	int replacedVal, newVal;
	cout << "Enter a value that will be replaced:" << endl;
	cin >> replacedVal;

	cout << "Enter a new value" << endl;
	cin >> newVal;

	vector<int>::iterator iter = ivec.begin();
	cout << "Not replaced:" << endl;
	for (;iter != ivec.end(); ++iter)
		cout << *iter << " ";
	cout << endl;

	replace_if(ivec.begin(), ivec.end(), EQ_cls(replacedVal),newVal);

	cout << "Replaced:" << endl;
	for (iter = ivec.begin(); iter != ivec.end(); ++iter)
		cout << *iter << " ";
	cout << endl;

	return 0;
}
