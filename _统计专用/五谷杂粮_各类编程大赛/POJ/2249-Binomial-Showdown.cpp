//20090405
#include <iostream>
using namespace std;

int main()
{
	int n, k;
	unsigned long long result;

	while ((cin >> n >> k) && ((n != 0) || (k != 0))) {
		result = 1;

		//if k is more than half of n, then use the complement
		k = (k > n / 2) ? n - k : k;

		int i = 0;
		while(i < k) {
			result *= n - i;
			result /= i + 1;
			++i;
		}
		cout << result << endl;
	}

	return 0;
}