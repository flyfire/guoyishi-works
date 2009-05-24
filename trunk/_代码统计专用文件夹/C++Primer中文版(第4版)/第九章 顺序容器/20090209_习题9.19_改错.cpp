vector<int>::iterator iter = iv.begin();
while (iter != iv.begin() + iv.size() / 2) {
	if (*iter == same_val) {
		iter = iv.insert(iter, 2 * some_val);
		iter += 2;
	}
	else
		++iter;
}