#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main()
{
	vector<double> dvec;
	double dval;

	cout << "Enter double value for vector container(Ctrl+Z to end):"
		<< endl;
	while (cin >> dval)
		dvec.push_back(dval);

	cout << "Summation of elements in the vector(use 0):"
		<< accumulate(dvec.begin(), dvec.end(), 0)
		<< endl;

	cout << "Summation of elements in the vector(use 0.0):"
		<< accumulate(dvec.begin(), dvec.end(), 0.0)
		<< endl;

	return 0;
}
