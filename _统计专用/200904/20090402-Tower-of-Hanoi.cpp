//20090402 Tower of Hanoi
#include <iostream>
using namespace std;

void Move(int n, char StartPole, char FinalPole)
{
	static steps = 0;
	cout << "Step " << ++steps << " : ";
	cout << "Move " << n << " from "
		<< StartPole << " to " << FinalPole << endl;
}

void Hanoi(int n,char StartPole, char MiddlePole, char FinalPole)
{
	if (n > 0) {
		Hanoi(n - 1, StartPole, FinalPole, MiddlePole);
		Move(n, StartPole, FinalPole);
		Hanoi(n - 1, MiddlePole, StartPole, FinalPole);
	}
}

int main()
{
	cout << "Tower of Hanoi" << endl;
	int n;
	cout << "Enter the number of Tower:";
	cin >> n;
	Hanoi(n, 'A', 'B', 'C');

	return 0;
}
