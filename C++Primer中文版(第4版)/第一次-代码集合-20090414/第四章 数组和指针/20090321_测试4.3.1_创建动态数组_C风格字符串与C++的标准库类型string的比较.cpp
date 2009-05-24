//20090321 Why they look same?
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

int main()
{
	clock_t start_c, finish_c;

	start_c = clock();

	const char *pc = "a very long literal string";
	const size_t len = strlen(pc);

	for (size_t ix = 0; ix != 1000000; ++ix) {
		char *pc2 = new char[len + 1];
		strcpy(pc2, pc);
		if (strcmp(pc2, pc))
			;	//do nothing
		delete [] pc2;
	}

	finish_c = clock();

	cout << "Time of C Style: " << finish_c - start_c << endl;

	clock_t start_str, finish_str;

	start_str = clock();

	string str("a very long literal string");
	for (int index = 0; index != 1000000; ++index) {
		string str2 = str;
		if (str != str2)
			;	//do nothing too
	}

	finish_str = clock();

	cout << "Time of String: " << finish_str - start_str << endl;

	return 0;
}