class Bulk_item : public Item_base {
public:
	double net_price(std::size_t) const;
private:
	std::size_t min_qty;
	double discount;
};

double net_price(std::size_t cnt) const
{
	if (cnt > min_qty)
		return cnt * (1 - discount) * price;
	else
		return cnt * price;
}