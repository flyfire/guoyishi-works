////////////////////////////////////////////////////////////////////
// Date:   2009-09-25
// Author: Yishi Guo
// Copy:   http://www.cse.unr.edu/~bebis/CS308/PowerPoint/Stacks.ppt
// About:  Iplementing stacks using dynamic array allocation
////////////////////////////////////////////////////////////////////
#include <iostream.h>

template<class ItemType>
class StackType{
	public:
		StackType(int);
		~StackType();
		void MakeEmpty();
		bool isEmpty() const;
		bool isFull() const;
		bool Push(ItemType);
		bool Pop(ItemType&);
	private:
		int top;
		int maxStack;
		ItemType* items;
};

template<class ItemType>
StackType<ItemType>::StackType(int max) {
	maxStack = max;
	items = new ItemType[maxStack];
	top = -1;
}

template<class ItemType>
StackType<ItemType>::~StackType() {
	delete[] items;
}

template<class ItemType>
void StackType<ItemType>::MakeEmpty() {
	top = -1;
	maxStack = -1;
	delete[] items;
}

template<class ItemType>
bool StackType<ItemType>::isEmpty() const {
	return (top == -1);
}

template<class ItemType>
bool StackType<ItemType>::isFull() const {
	return (top >= maxStack-1);
}

template<class ItemType>
bool StackType<ItemType>::Push(ItemType item) {
	if (!isFull()) {
		top++;
		items[top] = item;
	} else {
		return false;
	}

	return true;
}

template<class ItemType>
bool StackType<ItemType>::Pop(ItemType& item) {
	if (!isEmpty()) {
		item = items[top];
		// delete items[top];
		top--;
	} else {
		return false;
	}

	return true;
}

/**********************************************
int main() {
	int i;
	StackType<int> stack_int(10);

	stack_int.Push(1);
	stack_int.Push(2);
	stack_int.Push(3);
	
	stack_int.Pop(i);

	stack_int.Push(4);
	stack_int.Push(5);

	stack_int.Pop(i);

	stack_int.Push(6);
	stack_int.Push(7);

	while (!stack_int.isEmpty()) {
		stack_int.Pop(i);
		cout << i << ", ";
	}
	cout << endl;

	return 0;
}
*********************************************/