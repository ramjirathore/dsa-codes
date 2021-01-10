#include<iostream>
using namespace std;

// Inorder and Postorder Traversal

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

// Prorder Traversal
void printPre(node *root) {
	if (root == NULL) {
		return;
	}

	// Otherwise, print root first followed by subtrees(children)

	cout << root->data << " ";
	printPre(root->left);
	printPre(root->right);
}

// Inorder Traversal
void printIn(node *root) {
	if (root == NULL) {
		return;
	}

	// Otherwise, Left root Right

	printIn(root->left);
	cout << root->data << " ";
	printIn(root->right);
}


// Postorder Traversal
void printPost(node *root) {
	if (root == NULL) {
		return;
	}

	// Otherwise, Left Right root
        
	printPost(root->left);
	printPost(root->right);
	cout << root->data << " ";
}

int main() {
	node *root = buildTree();
	
	cout << "Preorder: ";
	printPre(root); 
	cout << endl;


	cout << "Inorder: ";
	printIn(root); 
	cout << endl;


	cout << "Postorder: ";
	printPost(root); 

	return 0;
}