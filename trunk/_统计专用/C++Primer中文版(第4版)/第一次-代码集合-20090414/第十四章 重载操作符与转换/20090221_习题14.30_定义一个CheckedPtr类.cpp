class CheckedPtr {
public:
	CheckedPtr(Screen *b, Screen *e): beg(b), end(e), curr(b) {}

	//解引用操作
	Screen& operator*();
	const Screen& operator*() const;

	//自增和自减操作
	//前缀式
	CheckedPtr& operator++();
	CheckedPtr& operator--();
	
	//后缀式
	CheckedPtr operator++(int);
	CheckedPtr operator--(int);

	//箭头操作
	Screen* operator->();
	const Screen* operator->() const;
private:
	Screen* beg;
	Screen* end;
	Screen* curr;
};

Screen& CheckedPtr::operator*()
{
	if (curr == end)
		throw out_of_range("invalid current pointer");
	return *curr;
}

const Screen& CheckedPtr::operator*() const
{
	if (curr == end)
		throw out_of_range("invalid current pointer");
	return *curr;
}

//前缀式
CheckedPtr& CheckedPtr::operator++()
{
	if (curr == end)
		throw out_of_range("increment past the end of CheckedPtr");
	++curr;
	return *this;
}

CheckedPtr& CheckedPtr::operator--()
{
	if (curr == beg)
		throw out_of_range("decrement past the beginning of CheckedPtr");
	--curr;
	return *this;
}

//后缀式
CheckedPtr CheckedPtr::operator++(int)
{
	//此处无需检查curr,由被调用的前自增操作进行检查
	CheckedPtr ret(*this);	//保存当前值
	++*this;				//调用前自增操作,进行检查
	return ret;				//返回被保存状态
}

CheckedPtr CheckedPtr::operator--(int)
{
	CheckedPtr ret(*this);
	--*this;
	return ret;
}

Screen* CheckedPtr::operator->()
{
	return curr;
}

const Screen* CheckedPtr::operator->() const
{
	return curr;
}
