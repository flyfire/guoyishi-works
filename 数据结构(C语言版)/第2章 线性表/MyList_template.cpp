////////////////////////////////////////////////////
// Date:     2009-11-08
// Author:   Yishi Guo
// Content:  Implements list using template
////////////////////////////////////////////////////
#include <iostream>
using namespace std;

template <class Type>
class Node {
	public:
		Node() {
		}
		Node( Type item ) {
			data = item;
			next = NULL;
		}
	public:
		Type data;
		Node* next;
};

template <class Type>
class MyList {
	public:
		MyList();
		void push( Type item );
		void insert( int, Type );
		Type pop();
		void remove( int );
		void display();
	private:
		Node<Type>* header;
		Node<Type>* curPtr;
		int size;
};

template <class Type>
MyList<Type>::MyList() {
	size = 0;
	header = new Node<Type>();
	curPtr = new Node<Type>();
}

template <class Type>
void MyList<Type>::push( Type item ) {
	Node<Type>* newNode = new Node<Type>();
	newNode->data = item;
	newNode->next = NULL;
	if ( size == 0 ) {
		header->next = curPtr->next = newNode;
	} else {
		curPtr->next = newNode;
	}
	curPtr = newNode;
	size++;
}

template <class Type>
void MyList<Type>::insert( int pos, Type item ) {
	if ( pos > size ) {
		return;
	}
	Node<Type>* newNode = new Node<Type>( item );
	Node<Type>* nodePtr = header;
	
	int i = 0;
	for ( i = 1; i < pos; ++i ) {
		nodePtr = nodePtr->next;
	}
	newNode->next = nodePtr->next;
	nodePtr->next = newNode;
}

template <class Type>
Type MyList<Type>::pop() {
	if ( size == 0 ) {
		return 0;
	}
	Node<Type>* nodePtr = header;
	int i = 0;
	for ( i = 1; i < size; ++i ) {
		nodePtr = nodePtr->next;
	}
	
	Type returnValue = nodePtr->next->data;
	
	curPtr = nodePtr;
	curPtr->next = NULL;
	--size;

	return returnValue;
}

template <class Type>
void MyList<Type>::remove( int pos ) {
	if ( pos > size || pos < 1 ) {
		return;
	}

	Node<Type>* nodePtr = header;
	int i = 0;
	for( i = 1; i < pos; ++i ) {
		nodePtr = nodePtr->next;
	}
	Node<Type>* deletePtr = nodePtr->next;
	nodePtr->next = nodePtr->next->next;
	delete( deletePtr );
	--size;
}

template <class Type>
void MyList<Type>::display() {
	Node<Type>* nodePtr = header;
	while ( nodePtr->next != NULL ) {
		nodePtr = nodePtr->next;
		cout << nodePtr->data << ' ';
	}
	cout << endl;
}

/**************** TEST CODE ***************
int main() {
	MyList<int> ilist;
	ilist.push( 1 );
	ilist.push( 2 );
	ilist.display();

	ilist.pop();
	ilist.push( 3 );
	ilist.push( 4 );
	ilist.insert( 2, 34 );
	ilist.display();

	ilist.push( 5 );
	ilist.remove( 2 );
	ilist.display();
	return 0;
}
*******************************************/