template <int hi, int wid>
class Screen {
	public:
		typedef std::string::size_type index;
		Screen() : content(hi * wid, '#'),
			cursor(0), height(hi), width(wid) {}
		Screen(const std::string& cont);
		char get() const
		{
			return contents[cursor];
		}

		char get(index ht, index wd) const;

		index get_cursor() const
		{
			return cursor;
		}

		Screen& move(index r, index c);
		Screen& set(char);
		Screen& display(ostream &os);
		const Screen& display(ostream &os) const;
	private:
		std::string contents;
		index cursor;
		index height, width;
};

template <int hi, int wid>
Screen<hi, wid>::Screen<hi, wid> (const std::string& cont) :
cursor(0), height(hi), width(wid)
{
	contents.assign(hi * wid, ' ');
	if (cont.size() != 0)
		contents.replace(0, cont.size(), cont);
}

template<int hi, int wid)
char Screen<hi, wid>::get(index r, index c) const
{
	index = row = r * width;
	return contents[row + c];
}

template<int hi, int wid>
Screen<hi, wid>& Screen<hi, wid>::set(char c)
{
	contents[cursor] = c;
	return *this;
}

template<int hi, int wid>
Screen<hi, wid>& Screen<hi, wid>::move(index r, index c)
{
	if (r >= height || c >= width) {
		cerr << "invalid row of column" << endl;
		throw EXIT_FAILURE;
	}

	index row = r * width;
	cursor = row + c;
	return *this;
}

template<int hi, int wid>
Screen<hi, wid>& Screen<hi, wid>::display(ostream &os)
{
	string::size_type index = 0;
	while (index != contents.size()) {
		os << contents[index];
		if ((index + 1) % width == 0) {
			os << '\n';
		}
		++index;
	}
	return *this;
}

template<int hi, int wid>
const Screen<hi, wid>& Screen<hi, wid>::display(ostream &os) const
{
	string::size_type index = 0;
	while (index != contents.size()) {
		os << contents[index];
		if ((index + 1) % width == 0) {
			os << '\n';
		}
		++index;
	}
	return *this;
}