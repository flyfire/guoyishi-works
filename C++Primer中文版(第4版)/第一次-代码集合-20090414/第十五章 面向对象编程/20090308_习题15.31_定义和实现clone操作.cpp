class Lds_item : public Item_base {
public:
	Lds_item* clone() const
	{
		return new Lds_item(*this);
	}
	//...
};