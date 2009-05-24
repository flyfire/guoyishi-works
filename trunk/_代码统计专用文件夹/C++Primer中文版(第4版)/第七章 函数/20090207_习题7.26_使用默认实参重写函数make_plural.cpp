#include <iostream>
#include <string>
using namespace std;

string make_plural(size_t ctr, const string &word, const string &ending = "s")
{
	return ctr == 1 ? word : word + ending;
}

int main()
{
	cout << "Singular version: " << make_plural(1, "success", "es")
		<< "\t\tplural version: "
		<< make_plural(0, "success", "es") << endl
		<< "Singular version: " << make_plural(1, "failure")
		<< "\t\tplural version: "
		<< make_plural(0, "failure") << endl;

	return 0;
}
