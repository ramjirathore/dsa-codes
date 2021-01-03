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


/***********PREVIOUS CODE****************/


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

int length(node *head) {
	int len = 0;
	while(head!=NULL) {
		head = head -> next;
		len++;
	}

	return len;
}

void insertInMiddle(node* &head, int data, int p) {

	if(head == NULL) {
		insertAtHead(head, data);
	} else if(p>length(head)) {
		insertAtTail(head, data);
	} else {
		int jump = 1;
		node *temp = head;

		// reach the correct position
		while(jump <= p - 1) {
			temp = temp -> next;
			jump++;
		}

		node *n = new node(data);
		n->next = temp->next;
		temp->next = n;
	}
} 


// passing head pointer by value
void  print(node *head) {
	while (head != NULL) {
		cout << head->data << " -> ";
		head = head -> next;
	}
	cout<<endl;
}

/**************END*******************/


void deleteHead(node* &head) {
	if(head == NULL) {
		return;
	}

	node *temp = head->next;
	delete head;
	head = temp;
}

void deleteTail(node* &head) {

	if(head == NULL) {
		return;
	}

	node *prev = head;
	while(prev->next->next != NULL) {
		prev = prev -> next;
	}

	node *tail = prev->next;
	prev->next = NULL;

	delete tail;

	tail = prev;
}


void deleteInMiddle(node* &head, int p) {
	if(head == NULL or p == 1) {
		deleteHead(head);
	} else if(p == length(head)) {
		deleteTail(head);
	} else {
		int jump = 1;
		node *prev = head;
		while(jump <= p-2) {
			prev = prev -> next;
			jump++;
		}

		node *temp = prev->next;
		prev->next = temp -> next;
		delete temp;
	}
}

int main() {
	node *head = NULL;

	/*** Previous code **/
	insertAtHead(head, 5);
	insertAtHead(head, 2);
	insertAtHead(head, 1);
	insertAtHead(head, 0);

	print(head);

	insertInMiddle(head, 4, 3);
	insertAtTail(head, 7);

	print(head);

	/**** end of previous code ***/

	deleteHead(head);
	print(head);

	deleteTail(head);
	print(head);

	deleteInMiddle(head, 3);
	print(head);

	return 0;
}