#include<iostream>
using namespace std;


// Find least common ancestor of two nodes 
// Intution -- we see that one node lie in the left subtree and one lie in right one
// Another case is when one is root itself ie LCA and the other is child
// So basically we try to search nodes in both left and right subtree


class node {
public: 
	int data;
	node *left; 
	node *right;

	node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};

node* buildTree() {
	int d;
	cin>>d;

	node *root = new node(d);

	if(d==-1) {
		return NULL;
	}

	root->left = buildTree();
	root->right = buildTree();

	return root;
}



node* lca(node *root, int a, int b) {
	if(root == NULL) {
		return NULL;
	}

	if(root->data == a or root->data == b) {
		return root;
	}	

	// search in left and right subtrees
	node *leftans = lca(root->left, a, b);
	node *rightans = lca(root->right, a, b);

	if(leftans!=NULL and rightans!=NULL) {
		return root;
	}

	if(leftans!=NULL) {
		return leftans;
	}

	return rightans;

}

int main() {
	node *root = buildTree();

	cout<<"LCA of 4 and 7 : " << lca(root, 4, 7)->data<<endl;
	cout<<"LCA of 6 and 9 : " << lca(root, 6, 9)->data;

}