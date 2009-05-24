#include <iostream>
#include <string>
using namespace std;

class Item_base {
public:
	Item_base(const std::string &book = "",
		double sales_price = 0.0):
	isbn(book), price(sales_price)
	{
		std::cout << "Item_base(const std::string&, double)"
			<< std::endl;
	}

	std::string book() const
	{
		return isbn;
	}

	virtual double net_price(size_t n) const
	{
		return n * price;
	}

	Item_base(const Item_base& ib) : isbn(ib.isbn), price(ib.price)
	{
		std::cout << "Item_base(const Item_base&)" << std::endl;
	}

	Item_base& operator= (const Item_base& rhs)
	{
		isbn = rhs.isbn;
		price = rhs.price;

		std::cout << "Item_base::operator =()" << std::endl;
		
		return *this;
	}

	virtual ~Item_base()
	{
		std::cout << "~Item_base()" << std::endl;
	}

private:
	std::string isbn;
protected:
	double price;
};

class Bulk_item : public Item_base {
public:
	Bulk_item(const std::string& book = "",
		double sales_price = 0.0,
		size_t qty = 0, double disc_rate = 0.0) :
	Item_base(book, sales_price),
		min_qty(qty), discount(disc_rate)
	{
		std::cout << "Bulk_item(const std::string&, double, size_t, double)"
			<< endl;
	}

	double net_price(size_t cnt) const
	{
		if (cnt >= min_qty)
			return cnt * (1 - discount) * price;
		else
			return cnt * price;
	}

	Bulk_item(const Bulk_item& b) :
	Item_base(b), min_qty(b.min_qty),
		discount(b.discount)
	{
		std::cout << "Bulk_item(const Bulk_item&)" << std::endl;
	}

	Bulk_item& operator= (const Bulk_item& rhs)
	{
		if (this != &rhs)
			Item_base::operator=(rhs);
		min_qty = rhs.min_qty;
		discount = rhs.discount;

		std::cout << "Bulk_item::operator=()" << std::endl;
		return *this;
	}

	virtual ~Bulk_item()
	{
		std::cout << "~Bulk_item()" << std::endl;
	}

private:
	size_t min_qty;
	double discount;
};

void func1(Item_base obj)
{
}

void func2(Item_base& obj)
{
}

Item_base func3()
{
	Item_base obj;
	return obj;
}

void print(const string& s)
{
	static count = 1;
	cout << endl << "#" << count++ << endl
		<< s << endl << endl;
}

int main()
{
	//#1
	print("Item_base iobj;");
	Item_base iobj;
	
	//#2
	print("func1(iobj);");
	func1(iobj);

	//#3
	print("func2(iobj);");
	func2(iobj);

	//#4
	print("iobj = func3();");
	iobj = func3();

	//#5
	print("Item_base *p = new Item_base;");
	Item_base *p = new Item_base;

	//#6
	print("delete p;");
	delete p;

	//#7
	print("Bulk_item bobj;");
	Bulk_item bobj;

	//#8
	print("func1(bobj);");
	func1(bobj);

	//#9
	print("func2(bobj);");
	func2(bobj);

	//#10
	print("Bulk_item *q = new Bulk_item;");
	Bulk_item *q = new Bulk_item;

	//#11
	print("delete q;");
	delete q;

	return 0;
}