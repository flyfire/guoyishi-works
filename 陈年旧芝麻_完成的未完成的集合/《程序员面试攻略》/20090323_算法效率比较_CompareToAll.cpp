#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int CompareToAll(int array[], int n)
{
	int i, j;
	bool isMax;

	if (n <= 0)
		return -1;

	for (i = n - 1; i > 0; --i) {
		isMax = true;
		for (j = 0; j < n; ++j) {
			if (array[j] > array[i])
				isMax = false;
		}
		if (isMax)
			break;
	}
	
	return array[i];
}

int main()
{
	int t1, t2;
	t1 = clock();

	int n;
	cout << "Enter \"n\"" << endl;
	cin >> n;
	int *pi = new int[n];

	int ix;
	for (ix = 0; ix < n; ++ix) {
		srand((unsigned int)time((time_t*)NULL));

		pi[ix] = rand();
	}

	cout << "The Max is: " << CompareToAll(pi, n) << endl;

	t2 = clock();
	cout << "TIME: " << t2 -t1 << endl;

	return 0;
}
