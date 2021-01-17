#include<iostream>
#include<queue>
using namespace std;


// LEVEL ORDER TRAVERSAL USING BFS
// 1. Either store the levels in each node of the queue
// Then print newline whenever the level changes

// 2.(suggested) Push a NULL node after each level
// And pop it out whenever it comes also push new NULL node (only if queue is not empty)
// since previous level is finished(because we caught its NULL node)
// else normally push the childs in queue as we did in BFS normally

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

	cout << "BFS Traversal: " << endl;

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

			cout << f->data << " ";

			if (f->left) q.push(f->left);
			if (f->right) q.push(f->right);
		}
	}

	return 0;
}
