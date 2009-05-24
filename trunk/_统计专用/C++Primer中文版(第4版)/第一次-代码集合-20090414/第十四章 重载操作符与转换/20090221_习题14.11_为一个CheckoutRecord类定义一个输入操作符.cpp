istream& operator >> (istream& in, CheckoutRecord& c)
{
	in >> c.book_id >> c.title
		>> c.date_borrowed >> c.date_due
		>> c.borrower.first >> c.borrower.second;
	if (!in) {
		c = CheckoutRecord();
		return in;
	}

	c.wait_list.clear();
	while (in) {
		pair<string, string> *ppa = new pair<string, string>;
		in >> ppa->first >> ppa->second;
		if (!in) {
			return in;
		}
		c.wair_list.push_back(ppa);
	}
	return in;
}