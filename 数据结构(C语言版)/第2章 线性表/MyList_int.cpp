////////////////////////////////////////
// Date: 2009-11-08
// Author: Yishi Guo
// Content: implement of integer list 
////////////////////////////////////////
#include <iostream>
using namespace std;

class Node {
public:
	Node() {
	}
	Node( int item ) {
		data = item;
		next = NULL;
	}
public:
	int data;
	Node* next;
};

class MyList {
public:
	MyList() {
		size = 0;
		header = new Node();
		curPtr = new Node();
	}

	void push( int item ) {
		Node* newNode = new Node();
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

	void insert( int pos, int item ) {
		if ( pos > size ) {
			return;
		}
		Node* newNode = new Node( item );
		Node* nodePtr = header;
		int i = 0;
		for ( i = 1; i < pos; ++i ) {
			nodePtr = nodePtr->next;
		}
		newNode->next = nodePtr->next;
		nodePtr->next = newNode;
	}

	int pop() {
		if ( size == 0 ) {
			return -1;
		}

		int i = 0;
		Node* nodePtr = header;
		for ( i = 1; i < size; ++i ) {
			nodePtr = nodePtr->next;
		}

		int returnValue = nodePtr->next->data;

		delete( nodePtr->next );  // delete node

		// For debug
		// cout << nodePtr->data << endl;

		curPtr = nodePtr;
		curPtr->next = NULL;
		size--;

		return returnValue;
	}

	void remove( int pos ) {
		if ( pos > size || pos < 1 ) {
			return;
		}
		Node* nodePtr = header;
		int i = 0;
		for ( i = 1; i < pos; ++i ) {
			nodePtr = nodePtr->next;
		}
		Node* deletePtr = nodePtr->next;
		nodePtr->next = nodePtr->next->next;
		delete( deletePtr );
		size--;
	}

	void display() {
		Node* curPtr = header;
		while ( curPtr->next != NULL ) {
			curPtr = curPtr->next;
			cout << curPtr->data << ' ';
		}
		cout << endl;
	}

private:
	Node* header;
	Node* curPtr;
	int size;
};

int main() {
	MyList list1;
	list1.push( 1 );
	list1.push( 2 );
	list1.push( 3 );
	cout << "Pop(): " << list1.pop() << endl;
	list1.push( 4 );
	list1.push( 5 );
	list1.display();

	list1.remove( 1 );
	list1.display();

	list1.insert( 1, 234 );
	list1.display();

	return 0;
}