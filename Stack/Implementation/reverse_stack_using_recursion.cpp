#include<iostream>
#include<stack>
using namespace std;

// PROBLEM - Reverse a stack using recursion
// SOLUTION -  Empty the stack using recursion then insert the popped out element at bottom

void insertAtBottom(stack <int> &s, int n) {
	if(s.empty()) {
		s.push(n);
		return; 
	}

	int data =  s.top();
	s.pop();
	insertAtBottom(s, n);
	s.push(data);
}

void reverse(stack<int> &s) {
	// base case
	if(s.empty()) {
		return;
	}

	// recursive case
	// pop out top element and insert it at bottom of 'reversed smaller stack'
	int x = s.top();
	s.pop();
	
	// recusively reverse the smaller stack
	reverse(s);
	
	insertAtBottom(s, x);

}

int main() {
	stack<int> s; 

	for(int i=1; i<5; i++) {
		s.push(i);
	}

	reverse(s);

	while(!s.empty()) {
		cout<<s.top()<<endl;
		s.pop();
	}

}