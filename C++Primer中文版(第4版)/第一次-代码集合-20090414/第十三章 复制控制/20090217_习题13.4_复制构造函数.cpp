//#1
NoName::NoName(const NoName& other)
{
	pstring = new std::string;
	*pstring = *(other.pstring);
	i = other.i;
	d = other.d;
}

//#2
NoName::NoName(const NoName& other):
pstring(new std::string(*(other.pstring))), i(other.i), d(other.d) { }