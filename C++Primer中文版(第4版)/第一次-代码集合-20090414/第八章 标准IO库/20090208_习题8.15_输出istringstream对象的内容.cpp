#include "20090208_get.hpp"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
	string line;
	cout << "Enter a line of text:" << endl;
	getline(cin, line);

	line += ' ';

	istringstream isstr(line);

	get(isstr);

	return 0;
}
