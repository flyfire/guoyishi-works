class Item_base {
	//...
public:
	virtual void debug(ostream& os = cout) const
	{
		os << isbn << "\t" << price;
	}
};

//...

class Disc_item : public Item_base {
	//...
public:
	virtual void debug(ostream& os = cout) const
	{
		Item_base::debug(os);
		os << "\t" << quantity << "\t"
			<< discount;
	}
};
