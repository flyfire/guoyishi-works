bool operator==(const CheckedPtr& lhs, const CheckedPtr& rhs)
{
	return lhs.beg == rhs.beg && lhs.end == rhs.end && lhs.curr == rhs.curr;	//ָ��ͬһ�����������
}

bool operator!=(const CheckedPtr& lhs, const CheckedPtr& rhs)
{
	return !(lhs == rhs);	//�໥��ϵ��������
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