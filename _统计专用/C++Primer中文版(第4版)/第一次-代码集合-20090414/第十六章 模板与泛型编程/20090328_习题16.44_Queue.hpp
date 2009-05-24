#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <list>
template <class Type> class Queue;
template <class T>
std::ostream& operator <<(std::ostream&, const Queue<T>&);

template <class Type> class Queue {
	friend std::ostream&
		operator << <Type> (std::ostream&, const Queue<Type>&);
	public:
		Queue() { }
	public:
		template <class It> Queue(It beg, It end): items(beg, end) { }
		template <class Iter> void assign(Iter beg, Iter end)
		{
			items.assign(beg, end);
		}

		Type& front()
		{
			return items.front();
		}

		const Type &front() const
		{
			return items.front();
		}

		void push(const Type &t)
		{
			items.push_back(t);
		}

		void pop()
		{
			items.erase(items.begin());
		}

		bool empty() const
		{
			return items.empty();
		}
	private:
		std::list<Type> items;
};

template <class Type>
std::ostream& operator << (std::ostream &os, const Queue<Type> &q)
{
	os << " < ";
	typename std::list<Type>::const_iterator beg = q.items.begin();
	while (beg != q.items.end()) {
		os << *beg << " ";
		++beg;
	}
	os << " > ";
	return os;
}

#endif