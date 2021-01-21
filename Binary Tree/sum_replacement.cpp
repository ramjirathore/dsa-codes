#include<iostream>
#include<queue>
using namespace std;


// SUM REPLACEMENT
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


int replaceSum(node *root) {
	if(root == NULL) return 0;

	if(root -> left == NULL && root->right == NULL) {
		return root->data;
	}

	int leftSum = replaceSum(root->left);
	int rightSum = replaceSum(root->right);

	int temp = root->data;
	root->data = leftSum + rightSum;

	return temp + root->data;
	
}

int main() {
	node *root = buildTree();

	bfs(root);

	replaceSum(root);
	cout<<endl;

	bfs(root);

	
	return 0;
}
