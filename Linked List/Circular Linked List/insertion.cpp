#include<iostream>
using namespace std;

class node {
public:
	int data;
	node *next;

	node(int d) {
		data = d;
		next = NULL;
	}
};


// STEPS: 
// add new node before head
// make last node point to new node
// point head to new node
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

	while(temp->next!=head) {
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	
	cout<<temp->data<<"->";
}

int main() {
	node *head = NULL;
	
	insertAtHead(head, 50);
	insertAtHead(head, 40);
	insertAtHead(head, 30);
	insertAtHead(head, 20);
	insertAtHead(head, 10);

	print(head);


}