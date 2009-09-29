///////////////////////////////////////////////////////////////////////////
// Data:    2009-09-25
// Author:  Yishi Guo
// Copy:    http://www.cse.unr.edu/~bebis/CS308/PowerPoint/Stacks.ppt
// About:   Stacks | Data Structures
///////////////////////////////////////////////////////////////////////////
#include <iostream.h>
#define MAX_ITEMS 100

template <class ItemType>
class StackType {
	public:
		StackType();
		void MakeEmpty();
		bool isEmpty() const;
		bool isFull() const;
		bool Push(ItemType);
		bool Pop(ItemType&);
	private:
		int top;
		ItemType items[MAX_ITEMS];
};

template <class ItemType>
StackType<ItemType>::StackType() {
	top = -1;
}

template <class ItemType>
void StackType<ItemType>::MakeEmpty() {
	top = -1;
}

template <class ItemType>
bool StackType<ItemType>::isEmpty() const {
	return (top == -1);
}

template <class ItemType>
bool StackType<ItemType>::isFull() const {
	return (top == MAX_ITEMS - 1);
}

template <class ItemType>
bool StackType<ItemType>::Push(ItemType item) {
	if (!isFull()) {
		top++;
		items[top] = item;
	} else {
		return false;
	}

	return true;
}

template <class ItemType>
bool StackType<ItemType>::Pop(ItemType& item) {
	if (!isEmpty()) {
		item = items[top];
		top--;
	} else {
		return false;
	}

	return true;
}

/*******************************************
// Test the stack
int main() {
	StackType<int> stack_int;
	int i;

	stack_int.Push(1);
	stack_int.Push(2);
	stack_int.Push(3);

	stack_int.Pop(i);

	stack_int.Push(4);
	stack_int.Push(5);

	stack_int.Pop(i);

	stack_int.Push(6);

	while (!stack_int.isEmpty()) {
		stack_int.Pop(i);
		cout << i << ", ";
	}
	cout << endl;

	return 0;
}
********************************************/
