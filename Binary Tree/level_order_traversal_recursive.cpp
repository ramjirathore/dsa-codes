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


int height(node *root) {
	if(root==NULL) return 0;

	int lSubTree = height(root->left);
	int rSubTree = height(root->right);

	return max(lSubTree, rSubTree) + 1;
}

void printKthLevel(node *root, int level) {
	if(root == NULL) return;

	if(level == 1) {
		cout<<root->data<<" ";
	}

	printKthLevel(root->left, level-1);
	printKthLevel(root->right, level-1);
}


// Recursive Approach - O(n*n) time and O(n) space
// For a skew tree of height n-> 
// You will traverse each level so 1 + 2 + 3 ... + n
// Thus O(n2) time
// and O(n) recursive stack space

void printLevelOrderRec(node *root) {
	int H = height(root);

	for(int k=1; k<=H; k++) {
		printKthLevel(root, k);
		cout<<endl;
	}
}


int main() {
	node *root = buildTree();
	
	cout<<"Level order Iterative:"<<endl;
	printLevelIterative(root);

	cout<<endl;
	cout<<endl;

	cout<<"Level order Recursive:"<<endl;
	printLevelOrderRec(root);
	
	return 0;
}