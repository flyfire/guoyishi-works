////////////////////////////////////////////
// Date:      2009-09-26
// Author:    Yishi Guo
// Chapter:   3.2.3
// Page:      49
////////////////////////////////////////////
#include <iostream.h>
#include "stack_mine.cpp"

void push_char(MyStack<char>& stack, char ch) {
	switch(ch) {
	case '#':
		stack.pop();
		break;
	case '@':
		stack.clear();
		break;
	default:
		stack.push(ch);
		break;
	}

	cout << "-- -- push(" << ch << ") -- --" << endl;
}

void output_stack(MyStack<char>& stack) {
	int i = 0;
	int size = stack.size();
	cout << "Size: " << size << endl;

	for( i = 0; i < size; ++i ) {
		cout << stack.top();
		stack.pop();
	}
	cout << endl;
}

int main() {
	MyStack<char> stack_char;
	char ch;

	while ( 1 ) {
		stack_char.clear();
		while ( cin >> ch ) {
			push_char(stack_char, ch);
		}
		cin.clear();
		output_stack(stack_char);

		cout << "Continue?(y/n): ";
		cin >> ch;
		if (ch == 'n' || ch == 'N') {
			break;
		}
	}

	return 0;
}