/////////////////////////////////////
// Date:     2009-09-26
// Author:   Yishi Guo
// Chapter:  3.2.2
// Content:  Match parentheses
// Page:     49
/////////////////////////////////////
#include <iostream>
#include "stack_mine.cpp"

void push_char(StackType<char>& stack, char ch) {
	stack.push(ch);
}

bool match_char(StackType<char>& stack, char ch) {
	if (stack.empty()) {
		return false;
	} else {
		if (stack.top() == '(' && ch == ')' ) {
			stack.pop();
			return true;
		} else if ( stack.top() == '[' && ch == ']' ) {
			stack.pop();
			return true;
		} else if ( stack.top() == '{' && ch == '}' ) {
			stack.pop();
			return true;
		}
	}

	return false;
}

int main() {
	StackType<char> stack;
	char ch;
	bool isOK = true;

	cout << "Enter expressions(Ctrl+Z to end):";

	while ( cin >> ch && isOK ) {
		switch( ch ) {
		case '(':
			push_char(stack, ch);
			break;
		case ')':
			if( !match_char(stack, ch) )  isOK = false;
			break;
		case '[':
			push_char(stack, ch);
			break;
		case ']':
			if ( !match_char(stack, ch) )  isOK = false;
			break;
		case '{':
			push_char(stack, ch);
			break;
		case '}':
			if ( !match_char(stack, ch) )  isOK = false;
			break;
		default:
			break;
		}
	}

	if(isOK) {
		cout << "Correct!" << endl;
	} else {
		cout << "Not correct" << endl;
		// For debug
		// cout << "Size:" << stack.size() << endl;
		// cout << "Top:" << stack.top() << endl;
	}

	return 0;
}
