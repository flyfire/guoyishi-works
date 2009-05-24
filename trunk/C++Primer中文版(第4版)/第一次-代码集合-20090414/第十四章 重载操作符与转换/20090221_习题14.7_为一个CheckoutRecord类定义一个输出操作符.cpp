#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <ostream>

class CheckoutRecord;
class CheckoutRecord {
public:
	friend ostream& operator<<(ostream&, CheckoutRecord&);
private:
	double book_id;
	string title;
	Date date_borrowed;
	Date date_due;
	pair<string, string> borrower;
	vector< pair<string, string>* > wait_list;
};

ostream& operator << (ostream& out, const CheckoutRecord& c)
{
	out << c.book_id << "\t" << c.title << endl
		<< "date borrowed: " << c.date_borrowed << endl
		<< "date due: " << c.date_due << endl
		<< "borrorwer: " << c.borrower.first << ", "
		<< c.borrower.second << endl;
	out << "wait list: " << endl;
	for (vector< pair<string, string>* >::const_iterator
		iter = c.wait_list.begin(); iter != c.wait_list.end(); ++iter)
		out << "\t" (*iter)->first << ". "
		<< (*iter)->second << endl;

	return out;
}

int main()
{
	return 0;
}