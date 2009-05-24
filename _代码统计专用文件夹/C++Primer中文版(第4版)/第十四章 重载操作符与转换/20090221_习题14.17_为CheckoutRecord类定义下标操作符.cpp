pair<string,string>& CheckoutRecord::operator[]
(const vector< pair<string, string>* >::size_type index)
{
	return *wait_list.at(index);
}

const pair<string, string>& CheckoutRecord::operator[]
(const vector< pair<string, string>* >::size_type index) const
{
	return *wait_list.at(index);
}