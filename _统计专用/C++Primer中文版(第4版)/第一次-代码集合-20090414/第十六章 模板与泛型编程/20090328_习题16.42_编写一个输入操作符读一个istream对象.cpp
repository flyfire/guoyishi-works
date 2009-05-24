template<class Type>
istream& operator >> (istream &is, Queue<Type> &q)
{
	Type val;
	while (is >> val)
		q.push(val);
	return is;
}