#include<iostream>
using namespace std;

// PREORDER build and printing

class node {
public:

	int data;
	node *left;
	node *right;

	node (int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};

node* buildTree() {
	int d;
	cin >> d;

	node *root = new node(d);

	if (d == -1) {
		return NULL;
	}

	root->left = buildTree();
	root->right = buildTree();


	return root;
}

void print(node *root) {
	if (root == NULL) {
		return;
	}

	cout << root->data << " ";

	print(root->left);
	print(root->right);
}


int main() {
	node *root = buildTree();
	print(root);

	return 0;
}