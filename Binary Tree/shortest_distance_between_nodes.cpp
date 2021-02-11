#include<bits/stdc++.h>
using namespace std;

// Shortest distance to find - meaning find the distance from A to B
// Two ways ->
// 1. Find distance from root to A : l1
//    then find distance from root to B: l2
//	  find lca's distance from root : lc
//	  => shortest dist = l1+l2 - 2(lc)	

// 2. Find lca then
//	  find dist from lca to A : l1
// 	  find dist from lca to B : l2
//    => shortest dis = l1 + l2

// We've used second method

class node {
public: 
	int data; 
	node *left; 
	node *right; 

	node(int d) {
		data = d; 
		left = right = NULL;
	}
};

node* buildTree() {
	int d;
	cin>>d; 

	if(d==-1) return NULL;

	node* root = new node(d);

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


// Finding the level of a given node from root/any given node
int search(node* root, int key, int level) {
	if(root == NULL) {
		return -1;
	}

	if(root->data == key) {
		return level;
	}

	int left = search(root->left, key, level+1);
	if(left!=-1) {
		return left;
	}
	// else search in right subtree
	return search(root->right, key, level+1);

}


// function to find distance between 2 nodes
int findDistance(node *root, int a, int b) {
	node *lca_node = lca(root, a, b);

	int l1 = search(lca_node, a, 0);
	int l2 = search(lca_node, b, 0);

	return l1 + l2;
}


int main() {
	node *root = buildTree();

	cout<<"LCA of 4 and 7 : " << findDistance(root, 4, 7)<<endl;
	cout<<"LCA of 6 and 9 : " << findDistance(root, 6, 9);

}