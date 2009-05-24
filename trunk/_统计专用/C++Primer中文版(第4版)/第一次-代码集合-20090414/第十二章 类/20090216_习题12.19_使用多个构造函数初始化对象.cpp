//#1
class NoName {
public:
	NoName()
	{
	}
	NoName(std::string *pstr, int iv, double dv)
	{
		pstring = pstr;
		ival = iv;
		dval = dv;
	}
private:
	std::string *pstring;
	int ival;
	double dval;
};
//#2
class NoName {
public:
	NoName();
	NoName(std::string *pstr, int iv, double dv);
private:
	std::string *pstring;
	int ival;
	double dval;
};

NoName::NoName()
{
}

NoName::NoName(std::string *pstr, int iv, double dv)
{
	pstring = pstr;
	ival = iv;
	dval = dv;
}