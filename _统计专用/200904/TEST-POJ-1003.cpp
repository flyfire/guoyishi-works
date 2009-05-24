//20090411
#include <iostream>
using namespace std;

int main()
{
	int cnt = 2;
	double sum = 0;
	while (cnt != 100) {
		sum += 1.0 / cnt;
		cout << "cnt = " << cnt++ << " sum : " << sum << endl;
	}

	return 0;
}