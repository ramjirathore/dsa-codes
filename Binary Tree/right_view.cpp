#include<iostream>
#include<queue>
using namespace std;


// Right view of Tree
// (Basically when you view from right of tree the nodes you see is right view)

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


// Perform preorder but do right before left
// also maintain level and maxlevel
// Update maxlevel when you reach new level
// Since the leftone call will have either level <= maxLevel
// Hence that never gets printed

void rightView(node *root, int level, int &maxLevel) {
	if(root == NULL) {
		return;
	}

	if(maxLevel < level) {
		// This means we have discovered a new level
		cout<<root->data<<" ";
		maxLevel = level;
	}

	//rec case

	rightView(root->right, level+1, maxLevel);
	rightView(root->left, level+1, maxLevel);

}


int main() {
	node *root = buildTree();


	bfs(root);
	cout<<endl;

	int maxLevel = -1;

	rightView(root, 0, maxLevel);
	

	return 0;
}
