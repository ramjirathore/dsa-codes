#include<iostream>
using namespace std;

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

/************end of prev code **********/

// void operator<<(ostream &os, node* head) {
// 	print(head);
// 	return;
// }


// os is cout basically
ostream& operator<<(ostream &os, node* head) {
	print(head);
	return os;
}

istream& operator>>(istream &is, node* &head) {
	head = takeInput();
	return is;
}

int main() {

	// Part 1:
	// // node *head = takeInput();

	// If you want to take two linked lists as input
	// One way->
	// // node *head2 = takeInput();

	// // cout<<head;
	// // cout<<head2;


	// Part2:

	// // cout << head << head2;
	// But if you do cout<<head<<head2;
	// This won't work because return type is void and
	// void << head2 --- doesn't makes sense


	// Part3:
	// so we update and return a ostream type return value
	// Now it works
	// // cout << head << head2;


	// Part4:
	// Lets overload >> also
	node *head;
	node *head2;
	cin >> head >> head2;
	cout << head << head2;

	// Similarly we can overload +, - ... operators also
	return 0;
}