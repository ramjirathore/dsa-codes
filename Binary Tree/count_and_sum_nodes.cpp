#include<iostream>
#include<queue>
using namespace std;


// Count all nodes and also find sum of all nodes

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


int countNodes(node *root) {
	if(root == NULL) {
		return 0;
	}

	return 1 + countNodes(root->left) + countNodes(root->right);
}

int sumOfAllNodes(node *root) {
	if(root == NULL) {
		return 0;
	}

	return root->data + sumOfAllNodes(root->left) + sumOfAllNodes(root->right);
}




int main() {
	node *root = buildTree();

	cout<<"Count: "<<countNodes(root)<<endl;;
	cout<<"Sum: "<<sumOfAllNodes(root);

	return 0;
}
