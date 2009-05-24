#include "20090308_Query.hpp"
#include "20090308_TextQuery.hpp"
#include <fstream>
#include <iostream>
using namespace std;

string make_plural(size_t, const string&, const string&);
void print_results(const set<TextQuery::line_no>& locs, const TextQuery &file)
{
	typedef set<TextQuery::line_no> line_nums;
	line_nums::size_type size =locs.size();
	cout << "match occurs "
		<< size << " "
		<< make_plural(size, "time", "s") << endl;

	line_nums::const_iterator it = locs.begin();
	for (; it != locs.end(); ++it) {
		cout << "\t(line "
			<< (*it) + 1 << ") "
			<< file.text_line(*it) << endl;
	}
}

int main()
{
	string fileName;

	cout << "Enter file name:" << endl;
	cin >> fileName;
	ifstream infile(fileName.c_str());
	if (!infile) {
		cerr << "No input file!" << endl;
		return EXIT_FAILURE;
	}

	TextQuery file;
	file.read_file(infile);

	typedef set<TextQuery::line_no> line_nums;

	Query q = Query("fiery") & Query("bird") | Query("wind");

	const line_nums &locs = q.eval(file);

	cout << "\nExecuted Query for: " << q <<  endl;

	print_results(locs, file);

	return 0;
}