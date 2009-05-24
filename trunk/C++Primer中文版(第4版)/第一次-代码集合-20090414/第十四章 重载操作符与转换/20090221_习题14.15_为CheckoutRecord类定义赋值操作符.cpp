CheckoutRecord&
CheckoutRecord::operator=(const CheckoutRecord& rhs)
{
	book_id = rhs.book_id;
	title = rhs.title;
	date_borrowed = rhs.date_borrowed;
	date_due = rhs.date_due;
	borrower = rhs.borrower;

	wait_list.clear();
	for (vector< pair<string, string>* >::const_iterator
			it = rhs.wait_list.begin();
			it != rhs.wait_list.end(); ++it) {
		pair<string, string> *ppa = new pair<string, string>;
		*ppa = **it;
		wait_list.push_back(ppa);
	}
	return *this;
}
