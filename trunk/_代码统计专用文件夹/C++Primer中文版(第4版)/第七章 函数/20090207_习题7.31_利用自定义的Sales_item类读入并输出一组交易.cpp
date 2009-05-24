#include "20090207_Sales_item.hpp"
#include <iostream>
using namespace std;

int main()
{
	Sales_item item;

	cout << "Enter some transaction(Ctrl+Z to end):"
		<< endl;
	while(item.input(cin)) {
		cout << "The transaction readed is:" << endl;
		item.output(cout);
		cout << endl;
	}

	return 0;
}