#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class GT_cls {
public:
	GT_cls(int val):bound(val) {}
		bool operator() (const int &value)
		{
			return value > bound;
		}
private:
	int bound;
};

int main()
{
	vector<int> vec;
	int val;
	cout << "Enter something(Ctrl+Z to end):" << endl;
	while (cin >> val)
		vec.push_back(val);

	cin.clear();

	int spval;
	cout << "Enter a specified value:"<< endl;
	cin >> spval;

	vector<int>::iterator iter;
	iter = find_if(vec.begin(), vec.end(), GT_cls(spval));

	if (iter != vec.end())
		cout << "The first element that is larger than "
		<< spval << " : "
		<< *iter << endl;
	else
		cout << "No element that is larger than "
		<< spval << endl;
	
	return 0;
}
