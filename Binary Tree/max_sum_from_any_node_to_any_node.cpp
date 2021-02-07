#include<bits/stdc++.h>
using namespace std; 

// Find max sum from any node to any node


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

class Pair {
public: 
	int branchSum;
	int maxSum;

	Pair() {
		branchSum = 0;
		maxSum = 0;
	}
};

node* buildTree() {
	int d; 
	cin >> d;

	if(d==-1) {
		return NULL;
	}

	node *root = new node(d);

	root-> left = buildTree();
	root ->right = buildTree();

	return root;
}


Pair maxSumPath(node *root) {
	Pair p;

	if(root == NULL) {
		return p;
	}


	Pair left = maxSumPath(root->left);
	Pair right = maxSumPath(root->right);


	// construct two values ie branchSum and maxSum

	int opt1 = root->data;
	int opt2 = left.branchSum + root->data;
	int opt3 = right.branchSum + root->data;
	int opt4 = left.branchSum + right.branchSum + root->data;

	int current_ans_through_root = max(opt1, max(opt2, max(opt3, opt4)));


	p.branchSum = max(left.branchSum, max(right.branchSum, 0)) + root->data;
	p.maxSum = max(left.maxSum, max(right.maxSum, current_ans_through_root));

	return p;

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

int main() {

	node *root = buildTree();

	bfs(root);

	cout<<"max sum from any node to any node: "<< maxSumPath(root).maxSum;

}