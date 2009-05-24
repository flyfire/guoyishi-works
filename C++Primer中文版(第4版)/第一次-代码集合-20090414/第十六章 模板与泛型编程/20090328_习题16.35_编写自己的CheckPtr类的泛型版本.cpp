template <typename T>
class CheckedPtr {
	public:
		CheckedPtr(T *b, T *e): beg(b), end(e), curr(b) {}

		CheckedPtr& operator++();
		CheckedPtr& operator--();
		CheckedPtr operator++(int);
		CheckedPtr operator--(int);

		T& operator[](const size_t index);
		const T& operator[](const size_t index) const;
		T& operator*();
		const T& operator*() const;
	private:
		T* beg;
		T* end;
		T* curr;
};

template <typename T>
CheckedPtr<T>& CheckedPtr<T>::operator++()
{
	if (curr == end)
		throw out_of_range ("increment past the end of CheckedPtr");
	++curr;
	return *this;
}

template <typename T>
CheckedPtr<T>& CheckedPtr<T>::operator--()
{
	if (curr == beg)
		throw out_of_range ("decrement past the beginning of CheckedPtr");
	--curr;
	return *this;
}

template <typename T>
CheckedPtr<T> CheckedPtr<T>::operator++(int)
{
	CheckedPtr ret(*this);
	++*this;
	return ret;
}

template <typename T>
CheckedPtr<T> CheckedPtr<T>::operator--(int)
{
	CheckedPtr ret(*this);
	--*this;
	return ret;
}

template <typename T>
T& CheckedPtr<T>::operator[] (const size_t index)
{
	if (beg + index >= end)
		throw out_of_range ("invalid index");
	return *(beg + index);
}

template <typename T>
const T& CheckedPtr<T>::operator[] (const size_t index) const
{
	if (beg + index >= end)
		throw out_of_range("invalid index");
	return *(beg + index);
}

template <typename T>
T& CheckedPtr<T>::operator*()
{
	if (curr == end)
		throw out_of_range("invalid current pointer");
	return *curr;
}

template <typename T>
const T& CheckedPtr<T>::operator*() const
{
	if (curr == end)
		throw out_of_range("invalid current pointer");
	return *curr;
}