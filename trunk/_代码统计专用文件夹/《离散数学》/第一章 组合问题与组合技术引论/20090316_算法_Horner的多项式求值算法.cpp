#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, x;
	double dval;
	vector<double> dvec;
	
	cout << "Enter n and x:" << endl;
	cin >> n >> x;

	int cnt = n + 1;
	while(cnt) {
		cout << "Enter a(" << --cnt << "):";
		cin >> dval;
		dvec.push_back(dval);
	}

	cout << "get the all values!" << endl;

	vector<double>::iterator iter = dvec.begin();
	int s = *iter++, k = 1;
	while (k <= n) {
		s = x * s + *iter;
		cout << "TEST #1 s = " << s << " x = " << x << " *iter = " << *iter << endl; //	TEST
		++iter;
		++k;
	}

	cout << "S = " << s << endl;

	return 0;
}