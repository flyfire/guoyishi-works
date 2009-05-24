#include <iostream>
#include <string>
using namespace std;

class Sales_item {
public:
	friend istream& read(istream&, Sales_item&);
	bool same_isbn(const Sales_item &rhs) const
	{
		return isbn == rhs.isbn;
	}

	Sales_item(const string &book = " "):
	isbn(book), units_sold(0), revenue(0.0) { }
private:
	string isbn;
	unsigned units_sold;
	double revenue;
};

istream& read(istream &is, Sales_item& obj)
{
	double price;
	is >> obj.isbn >> obj.units_sold >> price;
	if (is)
		obj.revenue = obj.units_sold * price;
	else
		obj = Sales_item();

	return is;
}

int main()
{
	return 0;
}
