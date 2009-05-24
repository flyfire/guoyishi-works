#ifndef MYVECTOR_H
#define MYVECTOR_H
#include <memory>
#include <cstddef>
using namespace std;

typedef T* iterator;

template <class T>
class Vector {
public:
	Vector(): elements(0), first_free(0), end(0) { }
	void push_back(const &T);
	void reserve(const size_t capa);

	void resize(const size_t n);

	void resize(const size_t n, const T& t);

	T& operator[] (const size_t);
	const T& operator[] (const size_t) const;

	size_t size()
	{	return first_free - elements; }

	size_t capacity()
	{	return end - elements; }

	iterator begin()
	{	return elements; }

	iterator end()
	{	return first_free; }
private:
	static std::allocator<T> alloc;
	void reallocate();
	T* elements;
	T* first_free;
	T* end;
};

#include "20090406-Vector.cpp"
#endif
