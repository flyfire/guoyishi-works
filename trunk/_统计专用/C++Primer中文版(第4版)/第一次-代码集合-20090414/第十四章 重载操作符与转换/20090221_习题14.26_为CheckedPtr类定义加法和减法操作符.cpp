CheckedPtr operator+(const CheckedPtr& lhs, const size_t n)
{
	CheckedPtr temp(lhs);
	temp.curr += n;
	if (temp.curr > temp.end)
		throw out_of_range("too large n");
	return temp;
}

CheckedPtr operator-(const CheckedPtr& lhs, const size_t n)
{
	CheckedPtr temp(lhs);
	temp.curr -= n;
	if (temp.curr < temp.beg)
		throw out_of_range("too large n");
	return temp;
}

ptrdiff_t operator-(CheckedPtr& lhs, CheckedPtr& rhs)
{
	if (!(lhs.beg == rhs.beg && lhs.end == rhs.end))
		throw out_of_range("too large n");
	return temp;
}