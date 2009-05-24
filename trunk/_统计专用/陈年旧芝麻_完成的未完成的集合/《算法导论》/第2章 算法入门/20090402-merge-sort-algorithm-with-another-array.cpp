//20090402 Merge sort with another array
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

template <typename T>
void merge(T a[], T temp[], int mid, int n)
{
	int i = 0;
	int j = mid;
	int k = 0;

	while (i < mid && j < n) {
		temp[k++] = (a[i] < a[j]) ? a[i++] : a[j++];
	}

	while (i < mid)
		temp[k++] = a[i++];

	while (j < n)
		temp[k++] = a[j++];

	for (i = 0; i != n; ++i)
		a[i] = temp[i];
}
template <typename T>
void merge_sort(T a[], T temp[], int n)
{
	if (n == 1)
		return;

	int mid = n / 2;

	merge_sort(a, temp, mid);
	merge_sort(a + mid, temp + mid, n - mid);
	merge(a, temp, mid, n);
}

int main()
{
	cout << "MERGE SORT" << endl;

	srand((unsigned)time(NULL));

	int n;
	cout << "Enter an integer:";
	cin >> n;

	int *array = new int[n];
	int *temp = new int[n];
	int i;
	for (i = 0; i != n; ++i) {
		array[i] = rand();
		cout << array[i] << " ";
		if ((i + 1) % 10 == 0)
			cout << endl;
	}
	cout << endl;

	cout << "First" << endl;
	merge_sort(array, temp, n);
	cout << "MERGE SORTED:" << endl;

	cout << "*array:" << endl;
	for (i = 0; i != n; ++i) {
		cout << array[i] << " ";
		if ((i + 1) % 10 == 0)
			cout << endl;
	}
	cout << endl;

	cout << "*temp:" << endl;
	for (i = 0; i != n; ++i) {
		cout << temp[i] << " ";
		if ((i + 1) % 10 == 0)
			cout << endl;
	}
	cout << endl;

	return 0;
}