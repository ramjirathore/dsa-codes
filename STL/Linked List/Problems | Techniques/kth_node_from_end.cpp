#include<iostream>
using namespace std;

// PROBLEM - Find Kth node from end
// SOLUTION -
// Basic one is first you find length and then traverse N-K node => two traversal
// Second is take fast pointer then jump it to K nodes then jump both slow and fast pointers
// one by one


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


node* kthNodeFromEnd(node *head, int k) {
	if (head == NULL or head->next == NULL) {
		return head;
	}

	node *slow = head;
	node *fast = head;

	int count = 0;

	//jump of k
	while (count < k) {
		fast = fast -> next;
		count++;
	}


	while (fast != NULL) {
		// jump of one now
		fast = fast->next;
		slow = slow -> next;
	}

	return slow;
}


int main() {

	node *head;
	cin >> head;
	cout << head;

	int k = 2;
	node *kthNode = kthNodeFromEnd(head, k);

	cout << kthNode->data << endl;

	return 0;
}