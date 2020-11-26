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


void reverse(node* &head) {
	node *curr = head, *prev = NULL;	
	node *n;

	while(curr!=NULL) {
		// save the next node
		n = curr->next;

		// make the current node point to prev node
		curr->next = prev;

		// update prev and curr, take them 1 step forward
		prev = curr;

		curr = n;
	}

	head = prev;
}

int main() {

	node *head;
	cin>>head;
	cout<<head;

	reverse(head);

	cout<<head;

	return 0;
}