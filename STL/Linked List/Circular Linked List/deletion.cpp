#include<iostream>
using namespace std;

/****** Prev code ********/
class node {
public:
	int data;
	node *next;

	node(int d) {
		data = d;
		next = NULL;
	}
};

void insertAtHead(node* &head, int data) {
	node *n = new node(data);
	node *temp = head;

	if (temp != NULL) {
		n->next = head;

		while (temp->next != head) {
			temp = temp ->next;
		}

		temp->next = n;
	} else {// inserting first node
		n->next = n;
	}

	head = n;
}

void print(node *head) {
	node *temp = head;

	while (temp->next != head) {
		cout << temp->data << "->";
		temp = temp->next;
	}

	cout << temp->data << "->" << endl;
}

/*****************************/

node* getNode(node *head, int data) {
	node *temp = head;

	// for all nodes except last node
	while (temp->next != head) {
		if (temp->data == data) {
			return temp;
		}
		temp = temp->next;
	}

	if (temp->data == data) {
		return temp;
	}

	return NULL;
}

void deleteNode(node* &head, int data) {
	node *del = getNode(head, data);

	if (del == NULL) {
		return;
	}

	node *temp = head;

	// if it is head node
	if (head == del) {
		head = head->next;
	}

	// stop one node behind the node to be deleted
	while (temp->next != del) {
		temp = temp->next;
	}
	temp->next = del->next;
	delete del;

}


int main() {
	node *head = NULL;

	insertAtHead(head, 5);
	insertAtHead(head, 4);
	insertAtHead(head, 3);
	insertAtHead(head, 2);
	insertAtHead(head, 1);

	print(head);

	deleteNode(head, 5);
	print(head);

	deleteNode(head, 1);
	print(head);

	return 0;
}