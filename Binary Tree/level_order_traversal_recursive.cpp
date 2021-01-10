#include<iostream>
#include<queue>
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

// Iterative approach
void printLevel(node *root) {
	if(root == NULL) return;

	queue<node*> q;

	q.push(root);

	while(!q.empty()) {
		node *temp = q.front();
		cout<<temp -> data<<" ";
		q.pop();

		if(temp->left != NULL)
			q.push(temp->left);
		
		if(temp->right != NULL)
			q.push(temp->right);
	}
}


int main() {
	node *root = buildTree();
	
	printLevel(root);
	
	return 0;
}