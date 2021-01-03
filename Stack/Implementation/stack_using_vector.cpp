#include<iostream>
#include<vector>
using namespace std;

// Implement stack using vector

class Stack {
private: 
	vector<int> v;
public: 
	void push(int n) {
		v.push_back(n);
	}
	int top() {
		return v[v.size()-1];
	}
	bool empty() {
		return v.size() == 0;
	}
	void pop() {
		if(!empty()) {
			v.pop_back();
		}
	}
};

int main() {
	Stack s;

	for(int i=1; i<=5; i++) {
		s.push(i*i);
	}

	while(!s.empty()) {
		cout<<s.top()<<endl;
		s.pop();
	} 

	return 0;
}