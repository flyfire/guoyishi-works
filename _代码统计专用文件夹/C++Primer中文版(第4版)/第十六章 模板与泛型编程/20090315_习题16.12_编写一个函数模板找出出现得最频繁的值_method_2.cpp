template <typename T>
typename T::value_type mostFre(T first, T last)
{
	std::size_t amount = 0;
	T start = first;
	while (start != last) {
		amount++;
		start++;
	}

	typedef std::vector<typename T::value_type> VecType;

	VecType vec(amount);
	VecType::iterator newFirst = vec.begin();
	VecType::iterator newLast = vec.end();

	std::uninitialized_copy(first, last, newFirst);

	std::sort (newFirst, newLast);

	std::size_t maxOccu = 0, occu = 0;

	VecType::iterator preIter = newFirst;
	VecType::iterator maxOccuElemIt = newFirst;

	while (newFirst != newLast) {
		if (*newFirst != *preIter) {
			if (occu > maxOccu) {
				maxOccu = occu;
				maxOccuElemIt = preIter;
			}
			occu = 0;
		}
		++ocuu;
		preIter = newFirst;
		++newFirst;
	}

	if (occu > maxOccu) {
		maxOccu = occu;
		maxOccuElemIt = preIter;
	}

	return *maxOccuElemIt;
}