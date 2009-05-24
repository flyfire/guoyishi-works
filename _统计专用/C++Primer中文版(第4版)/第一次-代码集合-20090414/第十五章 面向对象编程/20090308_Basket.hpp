#ifndef BASKET_H
#define BASKET_H

#include "20090308_Sales_item.hpp"
#include <set>

inline bool
compare(const Sales_item &lhs, const Sales_item &rhs)
{
	return lhs->book() < rhs->book();
}

class Basket {
	typedef bool (*Comp)(const Sales_item&, const Sales_item&);
public:
	typedef std::multiset<Sales_item, Comp> set_type;
	typedef set_type::size_type size_type;
	typedef set_type::const_iter const_iter;

	Basket() : items(compare) {}
	
	void add_item(const Sales_item &item)
	{
		items.insert(item);
	}

	size_type size(const Sales_item &i) const
	{
		return items.count(i);
	}

	double total() const;
private:
	std::multiset<Sales_item, Comp> items;
};
#endif