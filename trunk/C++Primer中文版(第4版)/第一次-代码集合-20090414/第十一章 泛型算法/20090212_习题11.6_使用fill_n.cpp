#include <iostream>
#include <algorithm>
#include <numeric>
#include <deque>
using namespace std;

int main()
{
	deque<int> idq(10,1);
	//OR	deque<int> idq(10);
	//OR	deque<int> idq;
	//		idq.resize(10);
	

	cout << "deque container:" << endl;
	deque<int>::iterator iter = idq.begin();
	while (iter != idq.end())
		cout << *iter++ << " ";
	cout << endl;

	fill_n(iter = idq.begin(), idq.size(), 0);
	while (iter != idq.end())
		cout << *iter++ << " ";
	cout << endl;

	fill(iter = idq.begin(), idq.end(), 2);
	while (iter != idq.end())
		cout << *iter++ << " ";
	cout << endl;

	return 0;
}
