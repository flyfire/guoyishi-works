#ifndef TEXTQUERY_H
#define TEXTQUERY_H
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cctype>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class TextQuery {
public:
	typedef string::size_type str_size;
	typedef vector<string>::size_type line_no;

	void read_file(ifstream &is)
	{
		store_file(is);
		build_map();
	}

	set<line_no> run_query(const string&) const;
	string text_line(line_no) const;
	line_no size() const;

private:
	void store_file(ifstream&);
	void build_map();

	vector<string> lines_of_text;

	map< string, set<line_no> > word_map;
	static string cleanup_str(const string&);
};
#endif