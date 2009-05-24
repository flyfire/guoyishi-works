#include <iostream>
using namespace std;

int main()
{
	int ival;

	cout << "Enter a number:" << endl;
	cin >> ival;
	
	int sum = 1;		//sum
	for(int i = 1; i <= ival; ++i){
		sum *= i;
	}

	cout << "Summation of them:" << endl
		<< sum << endl;	//sum

	return 0;
}
