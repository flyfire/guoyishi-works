template <typename T>
int compare(const T& v1, const T& v2)
{
	cout << "compare two objects" << endl;
	if (v1 < v2)
		return -1;
	if (v2 < v1)
		return 1;
	return 0;
}

template <class U, classT>
int compare(U v1,U v2, T beg)
{
	cout << "compare elements in two sequences" << endl;
	return 0;
}

int compare(const char* p1, const char* p2)
{
	cout << "plain function to handle C-style character strings"
		<< endl;
	return strcmp(p1, p2);
}