Sales_item Sales_item::operator+(const Sales_item& rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

Sales_item& operator+=(Sales_item& lhs, const Sales_item& rhs)
{
	lhs = lhs + rhs;
	return lhs;
}
