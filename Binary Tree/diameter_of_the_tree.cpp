#include<iostream>
#include<queue>
using namespace std;


// Diameter of tree - No. of nodes on the longest path between two leaves 
// It can pass through root node -> h1 + h2 ... h1 left subtree height, h2 right subtree height
// Diameter can exist in left sub tree only
// Diameter can exist in right sub tree only

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

int height(node *root) {
	if(root == NULL) return 0;

	int lHeight = height(root->left);
	int rHeight = height(root->right);

	return max(lHeight, rHeight) + 1;
}


// O(n*n) time complexity and O(n) space
int diameter(node *root) {
	if(root == NULL) return 0;

	int h1 = height(root->left); 
	int h2 = height(root->right);

	int opt1 = h1+h2;
	int opt2 = diameter(root->left); 
	int opt3 = diameter(root->right);

	return max(opt1, max(opt2, opt3));  
}

int main() {
	node *root = buildTree();

	cout<<"Diameter of Tree: "<<diameter(root);


	return 0;
}
