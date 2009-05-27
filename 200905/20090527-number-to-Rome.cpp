//20090527 by Yishi Guo
#include <iostream>
#include <string>

using namespace std;

int toRome(int number, int base)
{
	int i = 0;
	int n = i * base;

	while (n <= number) {
		i++;
		n = i * base;
	}

	return --i;
}

string toRome(string str, int n)
{
	string rome = "";
	int i = 0;

	while (i < n) {
		rome += str;
		i++;
	}

	return rome;
}

string toRome(int number)
{
	string rome = "";

	int M = toRome(number, 1000);
	rome += toRome("M", M);
	number -= M * 1000;

	int D = toRome(number, 500);
	rome += toRome("D", D);
	number -= D * 500;

	int C = toRome(number, 100);
	rome += toRome("C", C);
	number -= C * 100;

	int L = toRome(number, 50);
	rome += toRome("L", L);
	number -= L * 50;

	int X = toRome(number, 10);
	rome += toRome("X", X);
	number -= X * 10;

	int V = toRome(number, 5);
	rome += toRome("V", V);
	number -= V * 5;

	int I = toRome(number, 1);
	rome += toRome("I", I);

	return rome;
}

int main()
{
	int number;
	cout << "Enter a number: ";
	cin >> number;

	string rome = toRome(number);

	cout << "Rome: " << rome << endl;

	return 0;
}

