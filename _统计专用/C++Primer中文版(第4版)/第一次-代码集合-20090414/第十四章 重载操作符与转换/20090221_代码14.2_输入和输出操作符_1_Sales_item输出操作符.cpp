ostream& operator<<(ostream& out, const Sales_item& s)
{
	out << s.isbn << "\t" << s.units_sold << "\t"
		<< s.revenue << "\t" << s.avg_price();

	return out;
}