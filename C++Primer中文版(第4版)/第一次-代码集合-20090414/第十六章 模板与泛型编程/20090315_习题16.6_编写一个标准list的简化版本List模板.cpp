template <class Type>
class List {
	public:
		List();

		List(const List&);
		List operator=(const List&);
		~List();
		
		void insert(Type *ptr, const Type& value);
		void del(Type *ptr);
		Type *find(const Type& value);
		Type& getElem(Type *ptr);
		bool empty() const;
	private:
		//...
};