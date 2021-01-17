#include<iostream>
#include<queue>
using namespace std;


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


int main() {
	node *root = buildTree();

	cout<<"BFS Traversal: "<<endl;

	queue<node*> q;

	q.push(root); 

	while(!q.empty()) {
		node *f = q.front();
		q.pop();

		cout<<f->data<<" ";

		if(f->left) q.push(f->left);
		if(f->right) q.push(f->right);
	} 

	return 0;
}
