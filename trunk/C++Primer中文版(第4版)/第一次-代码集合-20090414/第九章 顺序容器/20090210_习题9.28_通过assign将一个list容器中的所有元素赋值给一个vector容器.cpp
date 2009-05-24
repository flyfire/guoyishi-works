//Wrong!
#include <iostream>
#include <list>
#include <vector>
#include <string>
using namespace std;

int main()
{
	char* sa[] = {"John", "Merry", "Tom", "Stone"};
	size_t sa_size = sizeof(sa) / sizeof(*sa);
	list<char*> slst(sa, sa+sa_size);

	vector<string> svec;
	svec.assign(slst.begin(), slst.end());	//Wrong!

	//输出list容器中的元素
	list<char*>::iterator lit = slst.begin();
	while (lit != slst.end())
		cout << *lit++ << " ";
	cout << endl;

	vector<string>::iterator vit = svec.begin();
	while (vit != svec.end())
		cout << *vit++ << " ";
	cout << endl;

	return 0;
}
