Sales_item& Sales_item::operator-=(const Sales_item& rhs)
{
	units_sold -= rhs.units_sold;
	revenue -= rhs.revenue;
	return *this;
}

Sales_item operator-(const Sales_item& lhs, const Sales_item& rhs)
{
	Sales_item ret(lhs);
	ret -= rhs;
	return ret;
}