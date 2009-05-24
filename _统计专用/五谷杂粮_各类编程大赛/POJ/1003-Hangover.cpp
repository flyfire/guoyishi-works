//20090411 Hangover
#include <iostream>
using namespace std;

int main()
{
	int cnt = 2;
	double wanted;
	double sum = 0;
	while (cin >> wanted && wanted) {
		cnt = 2;
		sum = 0;
		while (sum < wanted) {
			sum += 1.0 / cnt++;
		}
		cout << cnt - 2 << " card(s)" << endl;
	}

	return 0;
}