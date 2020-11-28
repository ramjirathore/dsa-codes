#include<iostream>
using namespace std;

// PROBLEM - Sort linked list using merge sort
// SOLUTION - O(nlogn)
// 1. Divide
// 2. Sort
// 3. Merge

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

node* takeInput() {
	node *head = NULL;

	int d;
	cin >> d;

	while (d != -1) {
		insertAtHead(head, d);
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


node* merge(node *a, node *b) {
	if (a == NULL) {
		return b;
	}
	if (b == NULL) {
		return a;
	}


	node *c;

	if (a->data < b->data) {
		c = a;
		c ->next =  merge(a->next, b);
	} else {
		c = b;
		c ->next =  merge(a, b -> next);
	}

	return c;
}

node* midpoint(node *head) {
	if (head == NULL or head->next == NULL) {
		return head;
	}

	node *slow = head;
	node *fast = head->next;

	while (fast != NULL and fast->next != NULL) {
		// jump of two
		fast = fast->next->next;

		//jump of one
		slow = slow -> next;
	}

	return slow;
}

node *mergeSort(node *head) {
	// base case
	if (head == NULL or head->next == NULL) {
		return head;
	}

	// Recursive case
	// 1. Break
	node *mid = midpoint(head);
	node * a = head;
	node * b = mid->next;

	mid->next = NULL;

	// 2. Rec sort both parts
	a = mergeSort(a);
	b = mergeSort(b);

	// 3. Merge them
	node *c = merge(a, b);
	return c;
}

int main() {

	node*head;

	cin >> head;
	cout << head;

	head = mergeSort(head);

	cout << head ;

	return 0;
}