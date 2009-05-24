#include <iostream>
#include <string>
#include <map>
#include <utility>
using namespace std;

int main()
{
	map<string, int> word_count;
	word_count["Anna"] = 1;
	cout << word_count["Anna"] << endl;

	++word_count["Anna"];

	cout << word_count["Anna"] << endl;

	return 0;
}