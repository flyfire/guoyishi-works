#include <iostream>
#include <string>
using namespace std;

int main()
{
	string word;
	while ( cin >> word ) {
		cout << "word read is: " << word << '\n';
		cout << "ok: no more words to read: bye!\n";
	}
	return 0;
}