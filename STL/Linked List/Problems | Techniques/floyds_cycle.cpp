#include<iostream>
using namespace std;

// #IMPO
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

// Only detection
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

////*************************/////

// We found meeting point 
// then moving the remaining distance 
// Crux: which is same from head to n and meet to n 
node* removeCycle(node* &head, node* meetPtr) {
	
	node *slow = head;
	node *fast = meetPtr;

	while(fast->next!=slow->next) { // Next Meet at n node + we find prev too
		slow = slow->next;
		fast = fast->next;
	}

	// make the prev to NULL
	fast->next = NULL;
}


// Detection and Removal
bool detectAndRemoveCycle(node *head) {
	node *slow = head;
	node *fast = head;

	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) {
			removeCycle(head, slow);
			return true;
		}
	}
	return false;
}

int main() {

	node *head = NULL;
	insertAtHead(head, 7);
	insertAtHead(head, 6);
	insertAtHead(head, 5);
	insertAtHead(head, 4);
	insertAtHead(head, 3);
	insertAtHead(head, 2);
	insertAtHead(head, 1);

	// creating a loop for testing
	head->next->next->next->next->next->next->next = head->next->next;

	if(detectAndRemoveCycle(head)) {
		cout<<"Cycle Detected and Removed"<<endl;
		cout<<head;
	} else {
	 	cout<<"Cycle Not Detected";
	}

	return 0;
}


// 1 -> 2 -> 3 -> 4
//          /      \
//         7 <-6 <- 5

// FLOYD REMOVAL:
// 1st meet: 6
// Break the distance at the meet and at cycle point (n)
// head to n: x
// n to meet: y
// meet to n: z

// ** Acc to floyd x=z
// Prove: 
// (Till meet)
// fast has travelled: x+2y+z
// slow has travelled: x+y
// till then : fast = 2*slow (speed)
// => x+2y+z = 2x+2z
// x=z Proved!