#include<iostream>
#include<list>
using namespace std; 

// Queue implementation using linked list

class Queue {
	list<int> l; 
	int cs;

public: 
	Queue() {
		cs = 0;
	}

	bool isEmpty() {
		return cs == 0;
	}

	void push(int data) {
		l.push_back(data);
		cs = cs + 1;
 	}

 	void pop() {
 		if(!isEmpty()) {
 			cs --;
 			l.pop_front();
 		}
 	}

 	int front() {
 		return l.front();
 	}
};

int main() {
	Queue q;

	for(int i=1; i<=10; i++) {
		q.push(i);
	}

	while(!q.isEmpty()) {
		cout<<q.front()<<" ";
		q.pop();
	}
}