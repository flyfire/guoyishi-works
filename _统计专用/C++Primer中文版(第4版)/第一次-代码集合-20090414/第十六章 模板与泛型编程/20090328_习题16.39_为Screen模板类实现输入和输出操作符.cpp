template<int hi, int wid>
std::ostream& operator << (std::ostream &os,const Screen<hi, wid> &s)
{
	os << "height: " << s.height
		<< "width: " << s.width
		<< "contents: " << s.contents;
	return os;
}

template<int hi, int wid>
std::istream& operator >> (std::istream &is, Screem<hi, wid> &s)
{
	std::string cont;
	is >> s.height >> s.width >> cont;

	s.contents.assign(s.height * s.width, ' ');

	if (cont.size() != 0)
		s.contents.replace(0, cont.size(), cont);

	return is;
}