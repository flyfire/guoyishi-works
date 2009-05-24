#include <iostream>
#include <cstdlib>
using namespace std;

template <typename T>
void merge_sort(T a[], int n)
{
	if (n == 1)
		return;

	int mid = n / 2;

	merge_sort(a, mid);
	merge_sort(a + mid, n - mid);

	T *s = new T[n];

	int i = 0;
	int j = mid;
	int k = 0;
	while (i < mid && j < n)
		s[k++] = (a[i] < a[j]) ? a[i++] : a[j++];

	while (i < mid)
		s[k++] = a[i++];
	while (j < n)
		s[k++] = a[j++];

	for (i = 0; i != n; ++i)
		a[i] = s[i];

	delete[] s;
}

int main()
{
	cout << "MERGE SORT BY MYSELF" << endl;
	int len;
	cout << "Enter array length:";
	cin >> len;
	int max;
	cout << "Enter max number:";
	cin >> max;

	int i;
	int *array = new int[len];
	for (i = 0; i != len; ++i) {
		array[i] = rand() % max;
		cout << i + 1 << "\t:\t" << array[i] << endl;
	}
	cout << endl;

	merge_sort(array, len);

	cout << "MERGED:" << endl;
	for (i = 0; i != len; ++i)
		cout << i + 1 << "\t:\t" << array[i] << endl;
	cout << endl;

	return 0;
}
