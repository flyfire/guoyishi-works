CheckoutRecord& CheckoutRecord::operator=(const Date& new_due)
{
	date_due = new_due;
	return *this;
}

CheckoutRecord& CheckoutRecord::operator=(const std::pair<string, string>& awaiter)
{
	pair<string, string> *ppa = new pair<string, string>;
	*ppa = awaiter;
	wair_list.push_back(ppa);
	return *this;
}