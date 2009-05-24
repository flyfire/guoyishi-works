#include <iostream>
#include <vector>
using namespace std;

double vectorSum(vector<double>::const_iterator begin,
				 vector<double>::const_iterator end)
{
	double sum = 0;
	while(begin != end){
		sum += *begin++;
	}

	return sum;
}

int main()
{
	vector<double> dvec;
	double dval;

	//Get
	cout << "Enter the double value(Ctrl+Z to end):" << endl;
	while(cin >> dval){
		dvec.push_back(dval);
	}

	//Put
	/********************************************************************
	*This is not good!
	*********************************************************************
	vector<double>::const_iterator begin = dvec.begin(),end = dvec.end();
	cout << "Sum of them:\t" << vectorSum(begin,end) << endl;
	*********************************************************************
	*/

	cout << "Sum of them:\t" << vectorSum(dvec.begin(), dvec.end()) << endl;

	return 0;
}