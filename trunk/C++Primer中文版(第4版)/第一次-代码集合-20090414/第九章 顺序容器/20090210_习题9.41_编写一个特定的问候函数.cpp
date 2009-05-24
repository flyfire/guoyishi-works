#include <iostream>
#include <string>
using namespace std;

string greet(string form, string lastname, string title,
			 string::size_type pos, int lenth) {
	form.replace(form.find("Daisy"), 5, lastname);
	form.replace(form.find("Ms"), 2, title, pos, lenth);

	return form;
}

int main()
{
	string generic1("Dear Ms Daisy:");
	string generic2("MrsMsMissPeople");

	string lastName("AnnaP");
	string salute = greet(generic1, lastName, generic2, 5, 4);

	cout << salute << endl;

	return 0;
}