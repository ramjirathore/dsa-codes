#include<iostream>
#include<queue>
using namespace std;


// Build Binary Tree from Preorder and Inorder

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


void bfs(node *root) {
	queue<node*> q;

	q.push(root);
	q.push(NULL);

	while (!q.empty()) {
		node *f = q.front();
		if (f == NULL) {
			cout << endl;
			q.pop();

			if (!q.empty()) {
				q.push(NULL);
			}
		} else {
			q.pop();

			cout << f->data << ", ";

			if (f->left) q.push(f->left);
			if (f->right) q.push(f->right);
		}
	}

}


// Intution - First node is always root node in preorder
// and in inorder the middle one is root
// so we traverse the preorder array
// and then find its index in inorder
// Left of this index will be left subtree
// Right of this index will be right subtree

node* buildTreefromTrav(int *in, int *pre, int s, int e) {
	
	// for traversing preorder array
	static int i = 0;

	// base case
	if(s>e) {
		return NULL;
	}

	// recursively call for the left and right half
	
	node* root = new node(pre[i]);

	// find index of value at i in inorder array
	int index = -1;

	for(int j=s; j<=e; j++) {
		if(in[j] == pre[i]) {
			index = j;
			break;
		}
	}

	// move forward in preorder array
	i++;

	root->left = buildTreefromTrav(in, pre, s, index-1);
	root->right = buildTreefromTrav(in, pre, index+1, e);

	return root;
}

int main() {

	int in[] =  {3,2,8,4,1,6,7,5};
	int pre[] = {1,2,3,4,8,5,6,7};
	int n = sizeof(in)/sizeof(in[0]);

	node *root = buildTreefromTrav(in,pre, 0, n-1);
	bfs(root);

	return 0;
}
