//

vector<int>::const_iterator find_val(
									 vector<int>::const_iterator beg,
									 vector<int>::const_iterator end,
									 int value,
									 vector<int>::size_type &occurs)	//&occurs
{
	vector<int>::const_iterator res_iter = end;
	occurs = 0;
	for(; beg != end; ++beg)
		if(*beg == value) {
			if(res_iter == end)
				res_iter = beg;
			++occusrs;
		}
	return res_iter;
}
