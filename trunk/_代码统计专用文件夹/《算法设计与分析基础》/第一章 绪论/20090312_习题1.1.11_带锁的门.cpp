#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int doorNumber;

	cout << "Enter door number:" << endl;
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
	for (vector<bool>::iterator iter = bvec.begin(); iter != bvec.end(); ++iter) {
		if(*iter) {
			cout << "1 ";
			++count;
		}
		else
			cout << "0 ";
	}
	cout << endl;

	cout << "Open door's number: " << count << endl;

	return 0;
}
