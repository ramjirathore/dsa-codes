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


// O(N) time And O(1) space (stack)
void reverse(node* &head) {
	node *curr = head, *prev = NULL;
	node *n;

	while (curr != NULL) {
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

// This is O(N*N) and O(N) stack space ---- (N due to recursion and N due to loop)
// node* recReverse(node* &head) {
// 	// if one node or no node then return
// 	if (head->next == NULL or head == NULL) {
// 		return head;
// 	}

// 	node *shead = recReverse(head->next); // small head

// 	node *temp = shead;
// 	while (temp->next != NULL) {
// 		temp = temp -> next;
// 	}

// 	head -> next =  NULL;
// 	temp -> next = head;

// 	return shead;
// }

// OPTIMIZATION -> the last node of small linked list is basically head->next
// O(N) time and O(N) stack space
node* recReverse(node* head) {
	// small linked list
	if (head->next == NULL or head == NULL) {
		return head;
	}

	// rec case
	node *shead = recReverse(head->next); // small head

	node *temp = head -> next; // OR you can skip this
	
	head -> next =  NULL; // AND write directly head->next->next = NULL;
	temp -> next = head;

	return shead;
}


int main() {

	node *head;
	cin >> head;
	cout << head;

	// reverse(head);
	head = recReverse(head);

	cout << head;

	// CONCLUSION - Best way to reverse is iterative one 
	// due to O(N) time and O(1) space

	return 0;
}