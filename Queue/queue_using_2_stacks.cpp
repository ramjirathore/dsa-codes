#include<iostream>
#include<stack>
using namespace std; 

// Implement Queue using two Stacks
// push - O(1) 
// pop - O(n) 
// top - O(n) 
// empty - O(1)


template<typename T>
class Queue {
	stack<T> s1, s2;
public: 
	void push(T data) {
		s1.push(data);
	}

	void pop() {
		// transfer n-1 elements from s1 in s2
		while(s1.size() > 1) {
			T element = s1.top();
			s2.push(element);
			s1.pop();
		}

		// remove last element
		s1.pop();

		// reinsert back into s1
		while(!s2.empty()) {
			s1.push(s2.top());
			s2.pop();
		}
	}

	T front() {
		// transfer n-1 elements from s1 in s2
		while(s1.size() > 1) {
			T element = s1.top();
			s2.push(element);
			s1.pop();
		}

		// store last element
		T front = s1.top();

		// reinsert back in s1
		while(!s2.empty()) {
			s1.push(s2.top());
			s2.pop();
		}

		// return stored element
		return front;
	}

	int size() {
		return s1.size() + s2.size();
	}

	bool empty() {
		return size() == 0; 
	}

};

int main() {
	Queue<int> q;

	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);

	while(!q.empty()) {
		cout<<q.front()<<" ";
		q.pop();
	}

	return 0;

}