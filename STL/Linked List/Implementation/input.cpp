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
	cout<<endl;
}

/************end of prev code **********/

// There are two ways - 
// either take head as input (by reference) and then insert 
// or insert values then return a head

void takeInput(node* &head) {
	int d;
	cin>>d;

	while(d!=-1) {
		insertAtHead(head, d);
		cin>>d;
	}
}

int main() {
	node *head = NULL;
	takeInput(head);

	print(head);

	return 0;
}