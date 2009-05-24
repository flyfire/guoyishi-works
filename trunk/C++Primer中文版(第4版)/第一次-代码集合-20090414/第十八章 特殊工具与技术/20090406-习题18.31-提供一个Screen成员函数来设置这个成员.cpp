//20090406 COPY!
class Screen {
public:
	typedef Screen& (Screen::*PmfType) ();
	typedef std::string::size_type index;

	Screen(PmfType p = &Screen::hone): pmf(p) { }

	void setPmf(PmfType p)
	{
		pmf = p;
	}

	PmfType getPmf()
	{
		return pmf;
	}

	char get() const;
	char get(index ht, index wd) const;
	Screen& home();
	Screen& forward();
	Screen& back();
	Screen& up();
	Screen& down();
private:
	std::string contents;
	index cursor;
	index height, width;
	PmfType pmf;
};