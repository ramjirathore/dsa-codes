#include<iostream>
#include<stack>
using namespace std;

// Problem - Check if given string has balanced parenthesis or not
// Solution - 
// Observation - First bracket closes in last => use stack
// Push in stack if there's opening bracket
// Pop in case of closing (if stack not empty)


bool isValidExp(string s) {
	stack<char> brackets;

	for(int i=0; i<s.length(); i++) {
		if(s[i] == '(') {
			brackets.push('(');
		}
		else if(s[i] == ')') {
			if(brackets.empty()) { // stack is empty so return 
				return false;
			}
			brackets.pop();
		}
	}

	// if empty means balanced else not
	return brackets.empty();
}

int main() {
	string s = "((a+b)+(c-d+f))";

	if(isValidExp(s)) {
		cout<<"Balanced parenthesis";
	} else {
		cout<<"Unbalanced parenthesis";
	}
}