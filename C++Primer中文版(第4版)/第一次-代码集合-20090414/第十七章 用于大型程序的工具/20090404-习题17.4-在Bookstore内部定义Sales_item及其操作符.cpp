//COPY!
namespace Bookstore {
	class Sales_item {
	public:
		Sales_item(const std::string &book = ""):
		  isbn(book), units_sold(0), revenue(0.0) { }
		  Sales_item(std::istream &is) { is >> *this; }

		  bool same_isbn(const Sales_item &rhs) const
		  { return isbn = rhs.isbn; }

		  std::string book() const
		  { return isbn; }

		  double avg_price() const;

		  friend std::istream& operator>>(std::istream& in, Sales_item &s);
		  friend std::ostream& operator<<(std::ostream& out, const Sales_item& s);

		  Sales_item& operator=(const std::string& str)
		  {
			  isbn = str;
			  return *this;
		  }

		  Sales_item& operator += (const Sales_item& rhs)
		  {
			  units_sold += rhs.units_sold;
			  revenue += rhs.revenue;
			  return *this;
		  }
	private:
		std::string isbn;
		unsigned units_sold;
		double revenue;
	};

	double Sales_item::avg_price() const
	{
		if (units_sold)
			return revenue / units_sold;
		else
			return 0;
	}

	std::istream& operator>>(std::istream& in, Sales_item& s)
	{
		double price;
		in >> s.isbn >> s.units_sold >> price;

		if (in)
			s.revenue = s.units_sold * price;
		else
			s = Sales_item();
		return in;
	}

	std::ostream operator<<(std::ostream& out, const Sales_item& s)
	{
		out << s.isbn << "\t" << s.units_sold << "\t"
			<< s.revenue;
		return out;
	}

	Sales_item operator + (const Sales_item& lhs, const Sales_item& rhs)
	{
		if (!lhs.same_isbn(rhs))
			throw isbn_mismatch("isbn mismatch", lhs.book(), rhs.book());
		Sales_item ret(lhs);
		ret += rhs;
		return ret;
	}
}

