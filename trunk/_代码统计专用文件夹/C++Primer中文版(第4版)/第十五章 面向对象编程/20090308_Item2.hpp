//Item2.hpp
#ifndef ITEM_H
#define ITEM_H
#include <string>

class Item_base {
public:
	Item_base(const std::string &book = "",
		double sales_price = 0.0):
	isbn(book), price(sales_price) {}

	std::string book() const
	{
		return isbn;
	}

	virtual double net_price (size_t n) const
	{
		return n * price;
	}

	virtual Item_base* clone() const
	{
		return new Item_base(*this);
	}

	virtual ~Item_base() {}
private:
	std::string isbn;
protected:
	double price;
};

class Disc_item : public Item_base {
public:
	Disc_item(const std::string& book ="",
		double sales_price = 0.0,
		size_t qty = 0, double disc_rate = 0.0):
	Item_base(book, sales_price),
		quantity(qty), discount(disc_rate) {}
	
	double net_price(size_t) const = 0;

	std::pair<size_t, double> discount_policy() const
	{
		return std::make_pair(quantity, discount);
	}
protected:
	size_t quantity;
	double discount;
};

class Bulk_item : public Disc_item {
public:
	Bulk_item(const std::string& book = "",
		double sales_price = 0.0,
		size_t qty = 0, double disc_rate = 0.0):
	Disc_item(book, sales_price, qty, disc_rate) {}

	double net_price(size_t cnt) const
	{
		if (cnt >= quantity)
			return cnt * (1 - discount) * price;
		else
			return cnt * price;
	}

	virtual Bulk_item* clone() const
	{
		return new Bulk_item(*this);
	}
};

class Lds_item : public Disc_item {
	Lds_item(const std::string& book = "",
		double sales_price = 0.0,
		size_t qty = 0, double disc_rate = 0.0):
	Disc_item(book, sales_price, qty, disc_rate) {}

	double net_price(size_t cnt) const
	{
		if (cnt <= quantity)
			return cnt * (1 - discount) * price;
		else
			return cnt * price - quantity * discount * price;
	}

	virtual Lds_item* clone() const
	{
		return new Lds_item(*this);
	}
};
#endif
