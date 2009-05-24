struct NoName {
	NoNane(): pstring(new std::string), i(0), d(0) { }
private:
	std::string *pstring;
	int i;
	double d;
};

NoName& NoName::operator=(const NoNane &rhs)
{
	pstring = new std::string;
	*pstring = *(rhs.pstring);
	i = rhs.i;
	d = rhs.d;
	return *this;
}