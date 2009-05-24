class NoName {
public:
	NoName(Screen *p): ptr(new ScreenPtr(p)) {}
	ScreenPtr operator->()
	{
		return *ptr;
	}

	const ScreenPtr operator->()
	{
		return *ptr;
	}
private:
	ScreenPtr *ptr;
};
