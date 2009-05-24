//20090404 merge sort with vector
#include <iostream>
#include <vector>
using namespace std;

vector<int> merge(vector<int>& left, vector<int>& right)
{
	vector<int> result;

	vector<int>::const_iterator l_iter = left.begin();
	vector<int>::const_iterator r_iter = right.begin();

	while (l_iter != left.end() && r_iter != right.end()) {
		result.push_back((*l_iter < *r_iter) ? *l_iter++ : *r_iter++);
	}

	while (l_iter != left.end())
		result.push_back(*l_iter++);

	while (r_iter != right.end())
		result.push_back(*r_iter++);

	return result;
}

	

void merge_sort(vector<int>& ivec)
{
	if (ivec.size() == 1)
		return;
	vector<int> left;
	vector<int> right;
	vector<int> result;

	int mid = ivec.size() / 2;

	int i;
	for (i = 0; i != mid; ++i) {
		left.push_back(ivec[i]);
	}

	for (i = mid; i != ivec.size(); ++i) {
		right.push_back(ivec[i]);
	}

	merge_sort(left);
	merge_sort(right);

	ivec = merge(left, right);
}

int main()
{
	int ival;
	vector<int> ivec;
	while (cin >> ival) {
		ivec.push_back(ival);
	}
	merge_sort(ivec);

	//output the result
	vector<int>::const_iterator iter;
	for (iter = ivec.begin(); iter != ivec.end(); ++iter) {
		cout << *iter << " ";
	}

	return 0;
}

