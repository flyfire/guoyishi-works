//TEST! 20090404
#include <iostream>

int main()
{
	int i = 0;
	while(i != 10) {
		using std::cout;
		int j = 0;
		while (j != 5) {
			using std::endl;
			cout << "j = " << j << endl;
		}
		cout << "i = " << i << endl;
	}

	cout << "finish!";

	return 0;
}
