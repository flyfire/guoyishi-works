template <class type>
Queue<Type>& Queue<Type>::operator = (const Queue &orig)
{
	destroy();
	copy_elems(orig);

	return *this;
}