#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include "20090308_Item.hpp"
using namespace std;

int main()
{
	vector<Item_base> itemVec;
	string isbn;
	double price, qty, discount;

	cout << "Enter some Bulk_item objects(Ctrl+Z to end):" << endl;
	cout << "isbn\tprice\tquantity\tdiscount" << endl;
	while (cin >> isbn >> price >> qty >> discount) {
		itemVec.push_back(Bulk_item(isbn, price, qty, discount));
	}

	double sum = 0.0;
	for (vector<Item_base>::iterator iter = itemVec.begin();
	iter != itemVec.end(); ++iter)
		sum += iter->net_price(100);

	cout << "Summation of net price: " << sum << endl;

	return 0;
}