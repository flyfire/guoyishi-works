#include <iostream>
using namespace std;

int sum1(const int *begin,const int *end)
{
	int sum = 0;
	while(begin != end){
		sum += *begin++;
	}

	return sum;
}

int sum2(const int ia[], size_t size)
{
	int sum = 0;
	for (size_t ix = 0; ix != size; ++ix){
		sum +=ia[ix];
	}

	return sum;
}

int sum3(int *begin,size_t size)
{
	int sum = 0;
	int *p = begin;
	while(p != begin + size){
		sum += *p++;
	}

	return sum;
}

int main()
{
	int ia[] = { 1, 2, 3, 4};
	cout << "Summation from sum1(): " << sum1(ia, ia+4) << endl;
	cout << "Summation from sum2(): " << sum2(ia,4) << endl;
	cout << "summation from sum3(): " << sum3(ia,4) << endl;

	return 0;
}