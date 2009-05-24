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
};

class Lds_item : public Disc_item {
public:
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
};