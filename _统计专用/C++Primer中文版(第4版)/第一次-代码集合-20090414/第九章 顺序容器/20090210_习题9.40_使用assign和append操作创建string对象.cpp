#include <iostream>
#include <string>
using namespace std;

int main()
{
	string q1("When lilacs last in the dooryard bloom'd");
	string q2("The child is father of the man");
	string sentence;

	cout << q1 << endl
		<< q2 << endl;

	sentence.assign(q2, 0 ,13);
	//OR
	//sentence.assign(q2.begin(), q2.begin()+13);
	cout << sentence << endl;

	//方案一
	//sentence.append(q1, 16, 16);
	//cout << sentence << endl;

	//方案二
	sentence.append(q1.substr(q1.find("in"),15));
	cout << sentence << endl;

	return 0;
}
