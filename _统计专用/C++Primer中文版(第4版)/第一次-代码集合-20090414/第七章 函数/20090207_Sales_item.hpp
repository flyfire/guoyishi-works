#include "20090207_Sales_item.h"

std::istream& Sales_item::input(std::istream& in)
{
	double price;
	in >> isbn >> units_sold >> price;
	if(in)
		revenue = units_sold * price;
	else {
		units_sold = 0;
		revenue = 0.0;
	}

	return in;
}

std::ostream& Sales_item::output(std::ostream& out) const
{
	out << isbn << "\t" << units_sold << "\t"
		<<revenue << "\t" << avg_price();
	return out;
}

double Sales_item::avg_price() const
{
	if(units_sold)
		return revenue/units_sold;
	else
		return 0;
}