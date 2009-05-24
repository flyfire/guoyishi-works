#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename InIt, typename T>
InIt& findElem(InIt first, InIt last, T &val)
{
	while (first++ != last) {
		if (*first == val) {
			return first;
	}
	return last;
}

int main()
{
	int ival;
	string str;
	vector<int> ivec;
	vector<string> svec;

	//about vector<int>
	cout << "Enter come integers(Ctrl+Z to end):" << endl;
	while (cin >> ival){
		ivec.push_back(ival);
	}
	cin.clear();

	int iElem;
	cout << "What you want find ?" << endl;
	cout << "Enter: ";
	cin >> iElem;

	vector<int>::iterator iter;
	if ((iter = findElem(ivec.begin(), ivec.end(), iElem)) != ivec.end())
		cout << "Found this element: " << *iter << endl;
	else
		cout << "Not found this element: " << iElem << endl;
	
	//about vector<string>
	cout << "Enter some strings(Ctrl+Z to end):" << endl;
	while (cin >> str) {
		svec.push_back(str);
	}
	cin.clear();

	string sElem;
	cout << "What you want find ?" << endl;
	cout << "Enter: ";
	cin >> sElem;

	vector<string>::iterator sit;
	if ((sit = findElem(svec.begin(), svec.end(), sElem)) != svec.end())
		cout << "Found this element: " << *sit << endl;
	else
		cout << "Not found this element: " << sElem << endl;

	return 0;
}
