bool operator==(const CheckedPtr& lhs, const CheckedPtr& rhs)
{
	return lhs.beg == rhs.beg && lhs.end == rhs.end && lhs.curr == rhs.curr;	//指向同一数组才有意义
}

bool operator!=(const CheckedPtr& lhs, const CheckedPtr& rhs)
{
	return !(lhs == rhs);	//相互联系起来定义
}

bool operator<(const CheckedPtr& lhs, const CheckedPtr& rhs)
{
	return lhs.beg == rhs.beg && lhs.end == rhs.end && lhs.curr < rhs.curr;
}

bool operator<=(const CheckedPtr& lhs, const CheckedPtr& rhs)
{
	return !(lhs > rhs);
}

bool operator>(const CheckedPtr& lhs, const CheckedPtr& rhs)
{
	return lhs.beg == rhs.beg && lhs.end == rhs.end && lhs.curr > rhs.curr;
}

bool operator>=(const CheckedPtr& lhs, const CheckedPtr& rhs)
{
	return !(lhs < rhs);
}