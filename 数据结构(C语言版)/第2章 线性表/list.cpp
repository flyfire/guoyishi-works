template <class ItemType>
class Node {
	public:
		Node(ItemType data, Node* next) {
			this->data = data;
			this->next = next;
		}
	public:
		ItemType data;
		Node* next;
};

template <class ItemType>
class List {
	public:
		List();
		~List();
		void push(ItemType);
		void insert(int,ItemType);
		void erase(int);
		void clear();
		void pop();
	private:
		Node* head;
		Node* index;
		int size;
};

template <class ItemType>
List::List() {
	head = new Node(NULL, NULL);
	index = head;
	size = 0;
}

template <class ItemType>
List::~List() {
}

template <class ItemType>
void List::push(ItemType item) {
	Node new_node = new Node(item, NULL);
	index.next = new_node;
	index = new_node;
	++size;
}

template <class ItemType>
void List::insert(int pos, ItemType item) {
	if (pos < size) {
		Node* node = head;
		
		int i = 0;
		while (i <= pos) {
			node = node.next;
		}

		Node* next_node = node.next;
		Node new_node = new Node(item, next_node);

		node.next = &new_node;
	}
}

template <class ItemType>
void List::erase(int pos) {
}

template <class ItemType>
void List::pop() {


		