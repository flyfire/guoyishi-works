template <>
class Queue<char*> {
public:
	void push(char*);
	void pop()
	{
		real_queue.pop();
	}

	bool empty() const
	{
		return real_queue.empty();
	}

	std::string front()
	{
		return real_queue.front();
	}

	const std::string &front() const
	{
		return real_queue.front();
	}

private:
	Queue<std::string> real_queue;
};

void Queue<char*>::push(char* val)
{
	return real_queue.push(val);
}