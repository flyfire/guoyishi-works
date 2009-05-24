//wrong!!!
#include <iostream>
#include <string>
using namespace std;

string make_plural(const string &word, const string &ending = "s", size_t ctr)
{
	return ctr == 1 ? word : word + ending;
}

int main()
{
	cout << "Singular version: " << make_plural("success", "es",1)
		<< "\t\tplural version: "
		<< make_plural("success", "es", 0) << endl
		<< "Singular version: " << make_plural("failure", , 1)
		<< "\t\tplural version: "
		<< make_plural("failure", , 1) << endl;

	return 0;
}
