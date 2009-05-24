int& CheckedPtr::operator[](const size_t index)
{
	if (beg + index >= end || beg + index < beg)	//end指向数组最后一个元素的下一位置
		throw out_of_range ("invalid index");
	return *(beg + index);
}

const int& CheckPtr::operator[](const size_t index)
{
	if (beg + index >= end || beg + index < beg)
		throw out_of_range ("invalid index");
	return *(beg + index);
}

int& CheckPtr::operator*()
{
	if (curr == end)
		throw out_of_range ("invalid current pointer");
	return *curr;
}

const int& CheckPtr::operator*() const
{
	if (curr == end)
		throw out_of_range ("invalid current pointer");
	return *curr;
}