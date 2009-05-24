//20090406 COPY!
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	vector<int> ivec;
	size_t i;
	for (i = 0; i != 10; ++i) {
		ivec.push_back(i);
		cout << ivec[i] << "\t";
	}
	cout << endl;

	cout << ivec.size() << "\t" << ivec.capacity() << endl;
	ivec.reserve(50);
	cout << ivec.size() << "\t" << ivec.capacity() << endl;
	ivec.resize(20);
	for (i = 0; i != 20; ++i)
		cout << ivec[i] << "\t";
	cout << endl;

	cout << ivec.size() << "\t" << ivec.capacity() << endl;
	cout << ivec[2] << "\t" << ivec[10] << endl;

	vector<string> svec;
	string str;

	cout << "Enter some strings(Ctrl+Z to end):" << endl;
	while (cin >> str) {
		svec.push_back(str);
	}

	for (i = 0; i != svec.size(); ++i)
		cout << svec[i] << "\t";
	cout << endl;

	cout << svec.size() << "\t" << svec.capacity() << endl;
	svec.reserve(120);
	cout << svec.size() << "\t" << svec.capacity() << endl;
	svec.resize(33);
	for (i = 0; i != svec.size(); ++i)
		cout << svec[i] << "\t";
	cout << endl;

	cout << svec.size() << "\t" << svec.capacity() << endl;
	cout << svec[2] << "\t" << svec[10] << endl;

	return 0;
}
