//Wrong!!!

#include <iostream>
using namespace std;

int add(int v1, int v2)
{
	return (v1 + v2);
}

double add(double v1, double v2)
{
	return (v1 + v2);
}

int main()
{
	cout << "Enter two numbers:" << endl;
	void v1,v2;
	cin >> v1 >> v2;
	cout << "Result: " << add(v1 + v2) << endl;

	return 0;
}