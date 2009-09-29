/////////////////////////////////////////////
// Date:       2009-09-25
// Author:     Yishi Guo
// Chapter:    3
// Content:    MyStacks | Data Structures
/////////////////////////////////////////////
#include <iostream.h>
#define MAX_SIZE 20
#define INCREMENT 2;

template<class ItemType>
class MyStack {
	public:
		MyStack();
		~MyStack();
		void clear();
		bool empty() const;
		int size() const;
		ItemType top();
		void push(const ItemType);
		void pop();
	private:  // Just for debug
	// public:  // Just for debug
		int index;
		int max;
		ItemType* items;
};

template<class ItemType>
MyStack<ItemType>::MyStack() {
	items = new ItemType[MAX_SIZE];
	index = -1;
	max = MAX_SIZE;
}

template<class ItemType>
MyStack<ItemType>::~MyStack() {
	delete[] items;
}

template<class ItemType>
void MyStack<ItemType>::clear() {
	while( index != -1 ) {
		this->pop();
		--index;
	}
}

template<class ItemType>
bool MyStack<ItemType>::empty() const {
	return ( index == -1 );
}

template<class ItemType>
int MyStack<ItemType>::size() const {
	return ( index+1 );
}

template<class ItemType>
ItemType MyStack<ItemType>::top() {
	if(!empty()) {
		return items[index];
	}
	return false;
}

template<class ItemType>
void MyStack<ItemType>::push( ItemType item ) {
	if (index == max - 1) {  // No more space for push
		ItemType* new_items = new ItemType[max];
		int i;
		for( i = 0; i < max; ++i ) {
			new_items[i] = items[i];
		}

		int new_max = max*INCREMENT;
		ItemType* old_pointer = items;
		items = new ItemType[new_max];
		// items = new_items;  // Could not be used

		for( i = 0; i < max; ++i ) {
			items[i] = new_items[i];
		}
		delete[] new_items;
		delete[] old_pointer;


		max *= INCREMENT;
	}
	++index;
	items[index] = item;
}

template<class ItemType>
void MyStack<ItemType>::pop() {
	if(!empty()) {
		--index;
	}
}

/************************************************
// For TEST
int main() {
	MyStack<int> MyStack_int;

	int i;
	for( i = 0; i < 10; ++i ) {
		MyStack_int.push(i);
	}

	for( i = 0; i <= MyStack_int.index; ++i ) {
		cout << MyStack_int.items[i] << ", ";
	}
	cout << endl;

	MyStack_int.pop();

	MyStack_int.push(11);

	for( i = 0; i <= MyStack_int.index; ++i ) {
		cout << MyStack_int.items[i] << ", ";
	}
	cout << endl;

	MyStack_int.clear();

	for( i = 0; i <= MyStack_int.index; ++i ) {
		cout << MyStack_int.items[i] << ", ";
	}
	cout << endl;

	for( i = 0; i < 220; ++i ) {
		MyStack_int.push(i);
	}

	for ( i = 0; i <= MyStack_int.index; ++i ) {
		cout << MyStack_int.items[i] << ", ";
	}
	cout << endl;

	cout << MyStack_int.top() << endl;

	return 0;
}
*************************************************/