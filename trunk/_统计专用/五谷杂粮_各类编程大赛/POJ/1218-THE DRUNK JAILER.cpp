//20090405 THE DRUNK JAILER
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	while (n--) {
		int k;
		cin >> k;
		vector<bool> bvec(k, false);
		int i = 0;
		while (i != k) {
			int j = 0;
			while (j != k) {
				if ((j + 1) % (i + 1) == 0) {
					if (bvec[j])
						bvec[j] = false;
					else
						bvec[j] = true;
				}
				++j;
			}
			++i;
		}
		int count = 0;
		for (vector<bool>::iterator iter = bvec.begin(); iter != bvec.end(); ++iter) {
			if (*iter)
				++count;
		}
		cout << count << endl;
	}

	return 0;
}