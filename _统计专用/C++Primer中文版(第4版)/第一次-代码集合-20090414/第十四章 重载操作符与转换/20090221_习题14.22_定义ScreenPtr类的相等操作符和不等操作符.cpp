inline bool
operator==(const ScreenPtr &lhs, const ScreenPtr &rhs)
{
	return lhs.ptr == rhs.ptr;
}

inline bool
operator==(const ScreenPtr &lhs, const ScreenPtr &rhs)
{
	return !(lsh == rhs);	//����==����������!=
}