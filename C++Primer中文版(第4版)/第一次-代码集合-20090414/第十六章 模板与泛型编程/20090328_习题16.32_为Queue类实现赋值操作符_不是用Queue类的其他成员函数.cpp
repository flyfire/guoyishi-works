template <class Type>
Queue<Type>& Queue<Type>::operator = (const Queue &orig)
{
	QueueItem<Type> *p = orig.head, *q;
	while (p != 0) {
		q = new QueueItem<Type>(p -> item);
		if (p == orig.head)
			head = tail = q;
		tail -> next = q;
		tail = q;
		p = p -> next;
	}
	return *this;
}