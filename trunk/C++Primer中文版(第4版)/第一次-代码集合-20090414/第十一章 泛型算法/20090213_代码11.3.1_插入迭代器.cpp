//ERROR!
#include <iostream>
#include <iterator>
#include <list>
using namespace std;

void print(list<int>::iterator beg, list<int>::iterator end)
{
	while (beg != end)
		cout << *beg++ << " ";
	cout << endl;
}

int main()
{
	list<int> ilst, ilst2, ilst3;
	for (list<int>::size_type i = 0; i != 4; ++i) {
		ilst.push_front(i);

		copy (ilst.begin(), ilst.end(), front_inserter(ilst2));

		copy (ilst.begin(), ilst.end(), inserter (ilst3, ilst3.begin()));
	}

	print(ilst.begin(), ilst.end());
	print(ilst2.begin(), ilst2.end());
	print(ilst3.begin(), ilst3.end());

	return 0;
}