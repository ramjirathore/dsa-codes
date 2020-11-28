#include<iostream>
using namespace std;

// PROBLEM - Detect cycle and removal it in a given linked list if there.

// SOLUTION- 
// --> O(N) time and O(1) space
// Detection - Take slow(1jump) and fast(2jumps) pointers.
// If they meet => Cycle .. else not

// Removal - Continuing with pointers..
// When they meet put slow point to head.
// make fast take 1 jump (same as slow).
// Where they meet now is the n node.
// make its prev->next = NULL
// done!


class node {
public:
	int data;
	node *next;

	// constructor
	node(int d) {
		data = d;
		next = NULL;
	}
};


/***********prev code *******/

// passing head pointer by reference
void insertAtHead(node* &head, int d) {
	node *n = new node(d);

	if (head == NULL) {
		head = n;
		return;
	}

	n -> next = head;
	head = n;
}

// passing head pointer by value
void  print(node *head) {
	while (head != NULL) {
		cout << head->data << " -> ";
		head = head -> next;
	}
	cout << endl;
}

// os is cout basically
ostream& operator<<(ostream &os, node* head) {
	print(head);
	return os;
}

/************end of prev code **********/

bool detectCycle(node *head) {
	node *slow = head;
	node *fast = head;

	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) {
			return true;
		}
	}
	return false;
}


int main() {

	node *head = NULL;
	insertAtHead(head, 5);
	insertAtHead(head, 3);
	insertAtHead(head, 2);
	insertAtHead(head, 1);
	insertAtHead(head, 4);

	// creating a loop for testing
	head->next->next->next->next = head->next;

	 if(detectCycle(head)) {
	 	cout<<"Cycle Detected";
	 } else {
	 	cout<<"Cycle Not Detected";
	 }

	return 0;
}