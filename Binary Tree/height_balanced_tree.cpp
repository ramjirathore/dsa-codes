#include<iostream>
#include<queue>
using namespace std;


// Check if it is Height Balanced Tree

// Replace root node's data with sum of left and right child values
// note: Leaf nodes won't get affected


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

class HBPair {
public: 
	int height;
	int balance;
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
};

HBPair isHeightBalance(node *root) {

	HBPair p;

	// Base case
	if(root == NULL) {
		p.height = 0;
		p.balance = true;
		return p;
	}

	// Recursive Case
	HBPair left = isHeightBalance(root->left);
	HBPair right = isHeightBalance(root->right);

	p.height = max(left.height, right.height) + 1;

	if(abs(left.height - right.height) <=1 && left.balance && right.balance) {
		p.balance =  true;
	} else {
		p.balance = false;
	}

	return p;
}





int main() {
	node *root = buildTree();

	if(isHeightBalance(root).balance) {
		cout<<"Height Balanced Tree";
	} else {
		cout<<"Not Height Balanced Tree";		
	}
	
	return 0;
}
