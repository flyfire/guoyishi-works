class Item_base {
	//...
public:
	//0:close
	virtual void debug(int ctrl = 1, ostream& os = cout) const
	{
		if (ctrl == 0)
			return ;
		
		os << isbn << "\t" << price;
	}
};

//...

class Disc_item : public Item_base {
	//...
public:
	//0 : close  1 : open
	virtual void debug(int ctrl = 1, ostream& os = cout) const
	{
		if (ctrl == 0)
			return;

		Item_base::debug(ctrl, os);
		os << "\t" << quantity << "\t"
			<< quantity;
	}
};
