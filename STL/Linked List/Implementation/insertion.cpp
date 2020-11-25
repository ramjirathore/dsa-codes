#include<iostream>
using namespace std;

// There are two ways :
// Either create a LinkedList class (Object ornexted Approach)
// or do separately in functions (Procedure oriented Approach)

// We'll prefer the latter one since its the one asked in interviews.


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

void insertAtTail(node* &head, int d) {
	node *n = new node(d);

	if (head == NULL) {
		head = n;
		return;
	}

	node *tail = head;

	// reach the end 
	while (tail->next != NULL) {
		tail = tail -> next;
	}

	tail -> next = n;
}


// passing head pointer by value
void  print(node *head) {
	while (head != NULL) {
		cout << head->data << " -> ";
		head = head -> next;
	}
	cout<<endl;
}


int main() {
	node *head = NULL;

	insertAtHead(head, 5);
	insertAtHead(head, 2);
	insertAtHead(head, 1);
	insertAtHead(head, 0);

	print(head);

	insertAtTail(head, 7);

	print(head);

	return 0;
}