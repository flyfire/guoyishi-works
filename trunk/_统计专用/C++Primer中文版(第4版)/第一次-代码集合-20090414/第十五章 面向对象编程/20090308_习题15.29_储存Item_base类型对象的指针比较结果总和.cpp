#include "20090308_Item.hpp"
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int main()
{
	vector<Item_base*> itemVec;
	string isbn;
	double price, qty, discount;

	cout << "Enter some Bulk_item objects(Ctrl+Z to end): " << endl;
	while (cin >> isbn >> price >> qty >> discount) {
		Bulk_item *p = new Bulk_item(isbn, price, qty, discount);
		itemVec.push_back(p);
	}

	double sum = 0.0;
	for (vector<Item_base*>::iterator iter = itemVec.begin();
	iter != itemVec.end(); ++iter)
		sum += (*iter)->net_price(100);

	cout << "summation of net price: " << sum << endl;

	for (iter = itemVec.begin(); iter != itemVec.end(); ++iter)
		delete *iter;

	return 0;
}