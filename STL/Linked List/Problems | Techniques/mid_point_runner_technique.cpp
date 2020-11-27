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

// os is cout basically
ostream& operator<<(ostream &os, node* head) {
	print(head);
	return os;
}

istream& operator>>(istream &is, node* &head) {
	head = takeInput();
	return is;
}

/************end of prev code **********/

// Observation - If we need to find mid point
// first we need to have length ie O(N)
// then we need to go till mid O(N/2)
// Better Approach -  We can do it in single iteration
// Maintain a fast pointer (taking 2 jumps)
// and a slow pointer (taking 1 jump)

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


int main() {

	node *head;
	cin >> head;
	cout << head;

	node *mid = midpoint(head);

	cout << mid->data << endl;

	return 0;
}