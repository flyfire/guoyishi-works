#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	stack<char> sexp;
	string exp;

	//������ʽ
	cout << "Enter a expression:" << endl;
	cin >> exp;

	//������ʽ
	string::iterator iter = exp.begin();
	while (iter != exp.end()) {
		if (*iter != ')')
			sexp.push(*iter);
		else {
			while (sexp.top() != '(' && !sexp.empty()) {
				sexp.pop();
			}

			if (sexp.empty())
				cout << "parentheses are not matched" << endl;
			else {
				sexp.pop();
				sexp.push('@');
			}
		}
		++iter;
	}
	return 0;
}
