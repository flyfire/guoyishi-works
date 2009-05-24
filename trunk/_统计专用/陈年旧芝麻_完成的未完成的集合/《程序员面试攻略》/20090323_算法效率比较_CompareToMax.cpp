#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int CompareToMax(int array[], int n)
{
	int curMax, i;

	if (n <= 0)
		return -1;

	curMax = array[0];

	for (i = 1; i < n; ++i) {
		if (array[i] > curMax) {
			curMax = array[i];
		}
	}

	return curMax;
}

int main()
{
	int t1, t2;
	t1 = clock();
	int n;
	cout << "Enter \"n\"" << endl;
	cin >> n;

	int *pi = new int[n];

	cout << "Enter the value:" << endl;
	int ix;
	for (ix = 0; ix < n; ++ix) {
		srand((unsigned int)time((time_t*)NULL));
		pi[ix] = rand();
	}

	cout << "Max of them: " << CompareToMax(pi, n) << endl;

	t2 = clock();
	cout << "OK!" << endl;
	cout << "TIME: " << t2 - t1 << endl;

	return 0;
}
