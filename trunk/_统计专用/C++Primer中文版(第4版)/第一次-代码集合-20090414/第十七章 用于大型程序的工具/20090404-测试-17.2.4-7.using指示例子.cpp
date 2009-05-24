#include <iostream>
using namespace std;

namespace blip {
	int bi = 88, bj = 12, bk = 11;
}

int bj = 0;

int main()
{
	using namespace blip;
	
	cout << bi << endl;
	//cout << bj << endl;
	cout << ::bj << endl;
	cout << blip::bj << endl;
	cout << bk << endl;

	int bk = 19881211;
	cout << bk << endl;

	return 0;
}
