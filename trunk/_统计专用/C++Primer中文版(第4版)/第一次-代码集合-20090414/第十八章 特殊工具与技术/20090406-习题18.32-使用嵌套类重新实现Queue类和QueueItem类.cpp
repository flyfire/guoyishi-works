//20090406 COPY!
template <class Type>
class Queue
{
public:
	Queue(): head(0), tail(0) { }

	Queue(const Queue &Q): head(0), tail(0)
	{	copy_elems(Q); }

	~Queue() {	destroy(); }

	Type& front()
	{
		return head->item;
	}

	const Type &front() const
	{
		return head->item;
	}

	void push(const Type &);

	void pop();

	bool empty() const
	{
		return head == 0;
	}

private:
	struct QueueItem {
		QueueItem(const Type &);
		Type item;
		QueueItem *next;
	};

	QueueItem *head;
	QueueItem *tail;

	void destroy();
	void copy_elems(const Queue&);
};

template <class Type>
void Queue<Type>::destroy()
{
	while (!empty())
		pop();
}

template <class Type>
void Queue<Type>::pop()
{
	QueueItem *p = head;
	head = head->next;
	delete p;
}

template <class Type>
void Queue<Type>::push(const Type &val)
{
	QueueItem *pt = new QueueItem(val);

	if (empty())
		head = tail = pt;
	else {
		tail->next = pt;
		tail = pt;
	}
}

template <class Type>
void Queue<Type>::copy_elems(const Queue &orig)
{
	for (QueueItem *pt = orig.head; pt; pt = pt->next)
		push(pt->item);
}

template <class Type>
Queue<Type>& Queue<Type>::operator = (const Queue &orig)
{
	head = tail = 0;
	copy_elems(orig);

	return *this;
}

template <class Type>
Queue<Type>::QueueItem::QueueItem(const Type &t):
item(t), next(0) { }