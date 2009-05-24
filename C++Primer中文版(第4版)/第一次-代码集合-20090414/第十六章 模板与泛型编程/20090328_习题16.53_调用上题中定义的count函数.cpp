#include "20090328_count.hpp"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	double da[] = {2.1, 2.2, 2.3, 3.4, 2.5, 2.6, 3.1};
	double dsa[] = {2.2, 4.2};

	int ia[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int isa[] = {2, 3, 7, 11};

	char ca[] = {'a', 'b', 'c', 'd', 'e'};
	char csa[] = {'b', 'f'};

	string sa[] = {"China", "Japan", "Hot", "Day"};
	string ssa[] = {"China", "Hot"};

	vector<double> dvec(da, da+7);
	vector<double> dsought(dsa, dsa+2);

	vector<int> ivec(ia, ia+10);
	vector<int> isought(isa, isa+4);

	vector<char> cvec(ca, ca+5);
	vector<char> csought(csa, csa+2);

	vector<string> svec(sa, sa+4);
	vector<string> ssought(ssa, ssa+2);

	cout << count(dvec, dsought) << endl;

	cout << count(ivec, isought) << endl;

	cout << count(cvec, csought) << endl;

	cout << count(svec, ssought) << endl;

	return 0;
}
