//20090402 BINARY SEARCH AND MERGE SORT
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//merge function
template <typename T>
void merge(T a[], int mid, int n)
{
	T *temp = new T[n];
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

	delete[] temp;
}

//merge sort main function
template <typename T>
void merge_sort(T a[], int n)
{
	if (n == 1)
		return;

	int mid = n / 2;
	merge_sort(a, mid);
	merge_sort(a + mid, n - mid);

	merge(a, mid, n);

}

//binary search main function
template <typename T>
bool binary_search(T a[], T value, int low, int high)
{
	if (low <= high) {
		int mid = (low + high) / 2;
		if (value == a[mid])
			return true;
		else if (value > a[mid])
			binary_search(a, value, mid + 1, high);
		else
			binary_search(a, value, low, mid - 1);
	}
	else
		return false;
}

int main()
{

	cout << "BINARY SEARCH" << endl;

	srand((unsigned)time(NULL));	//get random seed

	int n;
	cout << "Enter number:";
	cin >> n;

	int *array = new int[n];
	int i;
	for (i = 0; i != n; ++i) {
		array[i] = rand() % n;	//create random number
		cout << array[i] << " ";
		if ((i + 1) % 10 == 0)
			cout << endl;
	}
	cout << endl;

	merge_sort(array, n);	//sort the array first
	cout << "MERGE SORTED:" << endl;

	//print the sorted array
	for (i = 0; i != n; ++i) {
		cout << array[i] << " ";
		if ((i + 1) % 10 == 0)
			cout << endl;
	}
	cout << endl;

	//get the searchValue
	int searchValue;
	cout << "Enter the search value:";
	cin >> searchValue;


	int low = 0, high = n - 1;
	if (binary_search(array, searchValue, low, high))	//search the array
		cout << "Find " << searchValue << endl;
	else
		cout << "Could not find " << searchValue << endl;

	return 0;
}