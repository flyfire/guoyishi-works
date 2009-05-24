ScrenPtr& ScreenPtr::operator=(const ScreenPtr &rhs)
{
	++rhs.ptr->use;
	if (--ptr->use == 0)
		delete ptr;
	ptr = rhs.ptr;

	return *this;
}