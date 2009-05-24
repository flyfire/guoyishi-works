CheckedRecord::operator bool() const
{
	return wait_list.empty();
}