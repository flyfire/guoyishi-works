//2009021
#include <iostream>
using namespace std;

int main()
{
	const char ca[] = {'h', 'e', 'l', 'l', 'o'};
	const char *cp = ca;

	//have error about above code
	while (*cp) {
		cout << *cp << endl;
		++cp;
	}

	return 0;
}