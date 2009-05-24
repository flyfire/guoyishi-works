template <>
void Queue<char*>::push(char *const &val)
{
	char* new_item = new char[strlen(val) + 1];
	strncpy(new_item, val, strlen(val) + 1);

	QueueItem<char*> *pt =
		new QueueItem<char*>(new_item);

	if (empty())
		head = tail = pt;
	else {
		tail->next = pt;
		tail = pt;
	}
}

template <>
void Queue<char*>::pop()
{
	QueueItem<char*> *p = head;
	delete head->item;
	head = head->next;
	delete p;
}