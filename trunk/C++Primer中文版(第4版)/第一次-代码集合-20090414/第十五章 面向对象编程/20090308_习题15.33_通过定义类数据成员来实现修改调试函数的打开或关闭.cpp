#include <iostream>
#include <string>
using namespace std;

class Item_base {
	//...
public:
	Item_base(const std::string &book = "",
		double sales_price =0.0, bool dbg = false):
	isbn(book),price(sales_price), is_debug(dbg) {}

	//
	virtual void debug(ostream& os = cout) const
	{
		if (!is_debug)
			return;

		os << isbn << "\t" << price;
	}

	void set_debug(bool dbg)
	{
		is_debug = dbg;
	}

protected:
	bool is_debug;

private:
	double price;
	string isbn;
};

//...
class Disc_item : public Item_base {
	//...
public:
	Disc_item(const std::string& book = "",
		double sales_price = 0.0, size_t qty = 0,
		double disc_rate = 0.0, bool dbg = false):
	Item_base(book, sales_price, dbg),quantity(qty), discount(disc_rate) {}
	virtual void debug(ostream& os = cout) const
	{
		if (!is_debug)
			return;

		Item_base::debug(os);
		os << "\t" << quantity << "\t"
			<< discount;
	}
private:
	double quantity; 
	double discount;
};

class Bulk_item : public Disc_item {
	//...
public:
	Bulk_item(const std::string& book = "",
		double sales_price = 0.0, size_t qty = 0,
		double disc_rate = 0.0, bool dbg = false):
	Disc_item(book, sales_price, qty, disc_rate, dbg) {}
};

class Lds_item : public Disc_item {
	//...
public:
	Lds_item(const std::string& book = "",
		double sales_price = 0.0, size_t qty =0,
		double disc_rate = 0.0, bool dbg = false):
	Disc_item(book, sales_price, qty, disc_rate, dbg) {}
};

int main()
{
	return 0;
}