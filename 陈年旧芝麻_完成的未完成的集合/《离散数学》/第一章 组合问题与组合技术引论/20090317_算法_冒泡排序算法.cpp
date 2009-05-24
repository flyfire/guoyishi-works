#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int ival, n = 0, cnt = 0;
	vector<int> ivec;

	cout << "Enter some integers(Ctrl+Z to end):" << endl;
	while (cin >> ival) {
		ivec.push_back(ival);
		++n;
	}
	cin.clear();

	vector<int>::iterator iter_end = ivec.end() - 1;

	while (n--) {
		vector<int>::iterator iter2 = iter_end;
		vector<int>::iterator iter1 = iter2 -1;
		while (n && iter2 != ivec.begin()) {
			if (*iter1 > *iter2) {
				int tmp;
				tmp = *iter1;
				*iter1 = *iter2;
				*iter2 = tmp;
			}
			--iter1;
			--iter2;

			++cnt;
		}
	}

	cout << "Result(cnt = " << cnt <<"):" << endl;
	for (vector<int>::iterator iter = ivec.begin(); iter != ivec.end(); ++iter) {
		cout << *iter << " ";
	}

	return 0;
}