bool findInt (vector<int>::iterator beg, vector<int>::iterator end, int ival)
{
	while (beg != end)
		if (*beg == ival)
			break;
		else
			++beg;
	if (beg != end)
		return true;
	else
		return false;
}