#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int doorNumber;
	cin >> doorNumber;
	
	vector<bool> bvec(doorNumber, false);

	int i = 1;
	while (i <= doorNumber) {
		int j = i;
		while (j <= doorNumber) {
			if (j % i == 0) {
				if (bvec[j-1] == true)
					bvec[j-1] = false;
				else
					bvec[j-1] = true;
			}
			
			j += i;
		}
		i++;
	}

	vector<bool>::size_type count = 0;
	for (vector<bool>::iterator iter = bvec.begin(); iter != bvec.end(); ++iter)
		if(*iter)
			++count;

	cout << count;

	return 0;
}
