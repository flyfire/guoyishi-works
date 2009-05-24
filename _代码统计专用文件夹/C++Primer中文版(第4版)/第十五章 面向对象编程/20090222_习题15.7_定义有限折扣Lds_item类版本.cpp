class Lds_item : public Item_base {
public:
	Lds_item(const std::string book = "",
		double sales_price = 0.0,
		size_t qty = 0, double disc_rate = 0.0:
			Item_base(book, sales_price),max_qty(qty),discount(disc_rate) {	}
	double Lds_item::net_price(size_t cnt) const
	{
		if (cnt <= max_qty)
			return cnt * (1 - discount) * price;
		else
			return cnt * price - max_qty * discount * price;
	}
private:
	size_t max_qty;
	double discount;
};
