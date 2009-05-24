class CheckedPtr {
public:
	CheckedPtr(Screen *b, Screen *e): beg(b), end(e), curr(b) {}

	//�����ò���
	Screen& operator*();
	const Screen& operator*() const;

	//�������Լ�����
	//ǰ׺ʽ
	CheckedPtr& operator++();
	CheckedPtr& operator--();
	
	//��׺ʽ
	CheckedPtr operator++(int);
	CheckedPtr operator--(int);

	//��ͷ����
	Screen* operator->();
	const Screen* operator->() const;
private:
	Screen* beg;
	Screen* end;
	Screen* curr;
};

Screen& CheckedPtr::operator*()
{
	if (curr == end)
		throw out_of_range("invalid current pointer");
	return *curr;
}

const Screen& CheckedPtr::operator*() const
{
	if (curr == end)
		throw out_of_range("invalid current pointer");
	return *curr;
}

//ǰ׺ʽ
CheckedPtr& CheckedPtr::operator++()
{
	if (curr == end)
		throw out_of_range("increment past the end of CheckedPtr");
	++curr;
	return *this;
}

CheckedPtr& CheckedPtr::operator--()
{
	if (curr == beg)
		throw out_of_range("decrement past the beginning of CheckedPtr");
	--curr;
	return *this;
}

//��׺ʽ
CheckedPtr CheckedPtr::operator++(int)
{
	//�˴�������curr,�ɱ����õ�ǰ�����������м��
	CheckedPtr ret(*this);	//���浱ǰֵ
	++*this;				//����ǰ��������,���м��
	return ret;				//���ر�����״̬
}

CheckedPtr CheckedPtr::operator--(int)
{
	CheckedPtr ret(*this);
	--*this;
	return ret;
}

Screen* CheckedPtr::operator->()
{
	return curr;
}

const Screen* CheckedPtr::operator->() const
{
	return curr;
}
