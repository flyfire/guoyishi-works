#include <iostream>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main()
{
	vector<int> ivec;
	int ival;
	vector<string> svec;
	string str;

	cout << "Enter numbers(Ctrl+Z to end):" << endl;
	while (cin >> ival)
		ivec.push_back(ival);
	cin.clear();

	cout << "Enter some strings(Ctrl+Z to end):" << endl;
	while (cin >> str)
		svec.push_back(str);
	cin.clear();

	//查找大于1024的所有值
	cout << "all values that are greater than 1024:" << endl;
	vector<int>::iterator iter = ivec.begin();
	while ((iter = find_if(iter, ivec.end(), bind2nd(greater<int>(), 1024)))
		!= ivec.end()) {
		cout << *iter << " ";
		++iter;
	}

	//查找不等于"pooh"的所有字符串
	cout << endl << "all strings that are not equal to pooh:" << endl;
	vector<string>::iterator it = svec.begin();
	while ((it = find_if(it, svec.end(), bind2nd(not_equal_to<string>(), "pooh")))
		!= svec.end()) {
		cout << *it << " ";
		++it;
	}

	//将所有值乘以2
	transform(ivec.begin(), ivec.end(), ivec.begin(), bind2nd(multiplies<int>(), 2));
	cout << endl << "all values multiplies by 2:" << endl;
	for (iter = ivec.begin(); iter != ivec.end(); ++iter)
		cout << *iter << " ";

	return 0;
}
