#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
using namespace std;

int main()
{
	list<int> ilst;
	int ival;

	cout << "Enter some integers(Ctrl+Z to end):" << endl;
	while (cin >> ival)
		ilst.push_back(ival);
	cin.clear();

	/************错误的find用法
	list<int>::iterator iter =
		find(ilst.end(), ilst.begin(), 0);
	**********************************************/
	/******************正确的find用法***********/
	list<int>::reverse_iterator r_iter =
		find(ilst.rbegin(), ilst.rend(), 0);

	cout << "\t*iter = " << *r_iter << endl;

	if (r_iter != ilst.rend())
		cout << "element after the lase 0: "
		<< *(--r_iter) << endl;
	else
		cout << "no element 0" << endl;


	return 0;
}