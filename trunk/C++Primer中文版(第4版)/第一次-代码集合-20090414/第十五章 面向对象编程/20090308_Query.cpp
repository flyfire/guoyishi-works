#include "20090308_Query.hpp"
#include "20090308_TextQuery.hpp"
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;

set<TextQuery::line_no>
NotQuery::eval(const TextQuery& file) const
{
	set<TextQuery::line_no> has_val = query.eval(file);

	set<line_no> ret_lines;

	for (TextQuery::line_no n = 0; n != file.size(); ++n)
		if (has_val.find(n) == has_val.end())
			ret_lines.insert(n);
c
	return ret_lines;
}

set<TextQuery::line_no>
AndQuery::eval(const TextQuery& file) const
{
	set<line_no> left = lhs.eval(file),
		right = rhs.eval(file);

	set<line_no> ret_lines;

	set_intersection(left.begin(), left.end(),
		right.begin(),right.end(),
		inserter(ret_lines, ret_lines.begin()));

	return ret_lines;
}

set<TextQuery::line_no>
OrQuery::eval(const TextQuery& file) const
{
	set<line_no> right = rhs.eval(file),
		ret_lines = lhs.eval(file);

	for (set<line_no>::const_iterator iter = right.begin();
	iter != right.end(); ++iter)
		ret_lines.insert(*iter);

	return ret_lines;
}
