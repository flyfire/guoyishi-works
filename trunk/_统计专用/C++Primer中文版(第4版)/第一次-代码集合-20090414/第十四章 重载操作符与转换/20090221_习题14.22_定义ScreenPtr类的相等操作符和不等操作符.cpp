inline bool
operator==(const ScreenPtr &lhs, const ScreenPtr &rhs)
{
	return lhs.ptr == rhs.ptr;
}

inline bool
operator==(const ScreenPtr &lhs, const ScreenPtr &rhs)
{
	return !(lsh == rhs);	//根据==操作符定义!=
}