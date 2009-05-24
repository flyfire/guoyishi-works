#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

template <typename T>
void insertion_sort(T a[], int n)
{
	if (n == 0)
		return;
	
	insertion_sort(a, n-1);

	T key = a[n];
	int i = n;
	while (i > 0 && key < a[i-1]) {
		a[i] = a[i-1];
		--i;
	}
	a[i] = key;
}

int main()
{
	cout << "INSERTION SORT" << endl;
	srand((unsigned)time(NULL));
	int i;
	int *array = new int[100];
	for (i = 0; i < 30; ++i) {
		array[i] = rand();
		cout << array[i] << " ";
		if ((i + 1) % 10 == 0)
			cout << endl;
	}

	insertion_sort(array, 29);

	cout << "SORTED:" << endl;
	for (i = 0; i < 30; ++i) {
		cout << array[i] << " ";
		if ((i + 1) % 10 == 0)
			cout << endl;
	}

	return 0;
}