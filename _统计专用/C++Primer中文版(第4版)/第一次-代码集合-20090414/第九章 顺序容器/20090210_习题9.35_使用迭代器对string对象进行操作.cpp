#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	cout << "Enter a string:" << endl;
	getline(cin, str);

	cout << "What you have enter is:"
		<< str << endl;

	cout << "Upper:" << endl;
	for (string::iterator iter = str.begin(); iter != str.end(); ++iter) {
		if (isupper(*iter)) {
			cout << *iter << " ";
			str.erase(iter);
			--iter;
		}
	}

	cout << "Changed:" << endl
		<< str << endl;

	return 0;
}
