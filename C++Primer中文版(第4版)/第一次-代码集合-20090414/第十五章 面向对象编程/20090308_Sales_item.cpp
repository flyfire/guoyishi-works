#include "20090308_Sales_item.hpp"

Sales_item&
Sales_item::operator=(const Sales_item &rhs)
{
	++*rhs.use;
	decr_use();
	p = rhs.p;
	use = rhs.use;
	return *this;
}