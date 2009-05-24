class Query {
	friend Query operator~(const Query &);
	friend Query operator|(const Query&, const Query&);
	friend Query operator&(const Query&, const Query&);
public:
	Query(const string&);

	set<TextQuery::line_no> eval(const TextQuery &t) const
	{
		return h -> eval(t);
	}

	ostream &display(ostream &os) const
	{
		return h -> display(os);
	}

private:
	Query(Query_base *query):h(query) { }
	Handle<Query_base> h;
};

inline Query::Query(const string &s):h(new WordQuery(s)) { }

inline Query operator&(const Query &lhs, const Query &rhs)
{
	return new AndQuery(lhs, rhs);
}

inline Query operator|(const Query &lhs, const Query &rhs)
{
	return new OrQuery(lhs, rhs);
}

inline Query operator~(const Query &oper)
{
	return new NotQuery(oper);
}
