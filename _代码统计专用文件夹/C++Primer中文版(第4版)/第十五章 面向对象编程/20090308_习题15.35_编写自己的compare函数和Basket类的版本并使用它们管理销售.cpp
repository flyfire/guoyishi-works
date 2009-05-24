//15-35.cpp
#include "20090308_Basket.hpp"
#include "20090308_Sales_item.hpp"
#include <iostream>
using namespace std;

int main()
{
	Basket basker;
	Sales_item item1(Bulk_item("7-115-14554-7", 99, 20, 0.2));
	Sales_item item2(Item_base("7-115-14554-7", 39));
	Sales_item item3(Lds_item("7-115-14554-7", 50, 200, 0.2));
	Sales_item item4(Bulk_item("7-115-14554-7", 99, 20, 0.2));

	basket.add_item(item1);
	basket.add_item(item2);
	basket.add_item(item3);
	basket.add_item(item4);

	cout << basket.total() << endl;

	return 0;
}