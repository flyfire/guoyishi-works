#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	const char *cp1 = "Mary and Linda";
	const char *cp2 = " are friends.";

	size_t len = strlen(cp1) + strlen(cp2);
	char *result_str = new char[len + 1];
	strcpy(result_str, cp1);
	strcat(result_str, cp2);
	
	cout << result_str << endl;

	delete [] result_str;

	return 0;
}