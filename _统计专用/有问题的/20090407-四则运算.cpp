#include <iostream>
#include <string>
using namespace std;

//Judge the expression
bool isWellForm(string exp)
{
	int i;
	int left_parenthesis = 0, right_parenthesis = 0;
	for (i = 0; i != exp.size(); ++i) {
		cout << "#1" << endl;	//////////////////////////TEST
		if (exp[i] == '(')
			++left_parenthesis;
		else if (exp[i] == ')')
			++right_parenthesis;
	}

	if (left_parenthesis != right_parenthesis)
		return false;
	return true;
}

bool noParenthesis(string str)
{
	for (int i = 0; i != str.size(); ++i) {
		if (str[i] == '(' || str[i] == ')')
			return false;
	}
	return true;
}

bool no_M_D(string str)
{
	for (int i = 0; i != str.size(); ++i) {
		if (str[i] == '*' || str[i] == '/')
			return false;
	}

	return true;
}

void operate_no_M_D(string str)
{
}

void operate_no_parenthesis(string str)
{
	if (no_M_D(str))
		operate_no_M_D(str);
	else {
		int i;
		string left, op, right;
		bool flag = false, flag2 = false;
		for (i = 0; i != str.size(); ++i) {
			if (str[i] != '+' && str[i] != '-'
				&& str[i] != '*' && str[i] != '/') {
				if (flag) {
					right = str[i];	//add number to right
					flag2 = true;
				}
				else
					left += str[i];	//add number to left
			}
			if (str[i] == '+' || str[i] == '-') {
				left = "";	//clear the value
				flag = false;
			}
			if (str[i] == '*') {
				op = '*';
				flag = true;
			}
			if (str[i] == '/' && flag) {
				op = '/';
				flag = true;
			}
			if ((flag && flag2) && (str[i] == '+' || str[i] == '-'
				|| str[i] == '*' || str[i] == '/'))
				break;
		}
		cout << right << op << left << endl;	//////////////////TEST
			
	}
}

//operate the expression
void operate(string str)
{
	if (noParenthesis(str)) {
		operate_no_parenthesis(str);
	}
	else {
		if (!isWellForm(str)) {
			cout << "wrong input!" << endl;
			return;	//end the operate
		}
		cout << "Next #2" << endl;	////////////////////////////TEST
		string str2;
		int i;
		bool flag = false;
		for (i = 0; i != str.size(); ++i) {
			if (str[i] == '(') {
				if (flag) {
					str2 = "";
				}
				else {
					flag =true;
				}
			}
			if (flag)
				str2 += str[i];
			if (flag && str[i] == ')') {
				break;
			}
			cout << "#2 str2: " << str2 << endl;	//////////////////TEST
		}

		cout << "#3 str2 = " << str2 << endl;	////////////TEST
		string str3;
		for (i = 1; i != str2.size() - 1; ++i)
			str3 += str2[i];
		cout << "#4 str3 = " << str3 << endl;	///////////////TEST

		operate(str3);
	}
}


int main()
{
	string str;
	cout << "Enter:";
	cin >> str;
	operate(str);

	return 0;
}