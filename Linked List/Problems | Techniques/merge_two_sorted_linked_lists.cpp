#include<iostream>
using namespace std;

// PROBLEM - Merge two sorted linked lists into one
// SOLUTION -
// Use a third pointer and make recursive calls
// NOTE - we have used insert at Tail everywhere

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
	cout << endl;
}

node* takeInput() {
	node *head = NULL;

	int d;
	cin >> d;

	while (d != -1) {
		insertAtTail(head, d);
		cin >> d;
	}

	return head;
}

// os is cout basically
ostream& operator<<(ostream &os, node* head) {
	print(head);
	return os;
}

istream& operator>>(istream &is, node* &head) {
	head = takeInput();
	return is;
}

/***********end of prev code *******/


node* mergeSortedLinkedLists(node *a, node *b) {
	if (a == NULL) {
		return b;
	}
	if(b == NULL) {
		return a;
	}


	node *c;
	
	if(a->data < b->data) {
		c = a;
		c ->next =  mergeSortedLinkedLists(a->next, b);
	} else {
		c = b;
		c ->next =  mergeSortedLinkedLists(a, b -> next);
	}
	


	return c;
}


int main() {

	node *head1;
	node *head2;

	cin >> head1 >> head2;
	cout<<head1<<head2;
	
	node *newHead = mergeSortedLinkedLists(head1, head2);

	cout << newHead ;

	return 0;
}