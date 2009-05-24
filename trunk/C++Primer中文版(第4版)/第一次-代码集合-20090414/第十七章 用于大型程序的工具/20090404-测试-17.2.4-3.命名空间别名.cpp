#include <iostream>
using namespace std;

namespace FirstSpace {
	int returnself(int i)
	{
		return i;
	}
	namespace SecondSpace {
		int returndouble(int i)
		{
			return i * 2;
		}
	}
}

int main()
{
	namespace first = FirstSpace;
	namespace fst = first;
	namespace FirstSecond = FirstSpace::SecondSpace;

	int i = 10;
	cout << first::returnself(i) << endl;

	cout << fst::returnself(i) << endl;

	cout << FirstSpace::SecondSpace::returndouble(i) << endl;

	cout <<FirstSecond::returndouble(i) << endl;

	cout << "finish!" << endl;

	return 0;
}
