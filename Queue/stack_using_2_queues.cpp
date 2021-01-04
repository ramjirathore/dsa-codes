#include<iostream>
#include<queue>
using namespace std; 

// Implement Stack using two Queues
// push - O(1) (or we can do in O(n))
// pop - O(n) (or we can do in O(1))
// top - O(n) 
// empty - O(1)

template<typename T>
class Stack {
	queue<T> q1, q2; 

public: 
	void push(T data) {
		q1.push(data);
	}

	void pop() {
		// remove last added element from q1
		// we have to first n-1 elements from q1 in q2
		// interchange the names of q1 and q2

		if(q1.empty()) {
			return;
		}

		while(q1.size() > 1) {
			T el = q1.front();
			q2.push(el);
			q1.pop();
		}

		// remove last element from q1
		q1.pop();

		// swap names of q1 and q2 
		swap(q1, q2);
	}

	T top() {
		while(q1.size() > 1) {
			T el = q1.front();
			q2.push(el);
			q1.pop();
		}

		// 1 element in q1
		T element = q1.front();
		q1.pop();
		q2.push(element);

		// swap q1 and q2 names
		swap(q1, q2);


		// return the element
		return element;
	}

	int size() {
		return q1.size() + q2.size();
	}

	bool empty() {
		return size() == 0;
	}

};

int main() {
	Stack<int> s;

	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);

	while(!s.empty()) {
		cout<<s.top()<<endl;
		s.pop();
	}

	return 0;
}