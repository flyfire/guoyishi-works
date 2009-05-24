//method 1
template <typename T>
typename T::value_type mostFre(T first, T last)
{
	allocator<typename T::value_type> alloc;
	T newFirst = alloc.allocate(last - first);
	T newLast = newFirst + (last - first);

	std::uninitialized_copy(first, last, newFirst);

	std::sort (newFirst, newLast);

	std::size_t maxOccu = 0, occu = 0;
	T preIter = newFirst, maxOccuElemIt = newFirst;

	while (newFirst != newLast) {
		if (*newFirst != *preIter) {
			if (occu > maxOccu) {
				maxOccu = occu;
				maxOccuElemIt = preIter;
			}
			occu = 0;
		}
		++occu;
		preIter = newFirst;
		++newFirst;
	}
	if (occu > maxOccu) {
		maxOccu = occu;
		maxOccuElemIt = preIter;
	}

	return *maxOccuElemIt;
}