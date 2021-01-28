#include<iostream>
#include<queue>
using namespace std;


// Build Balanced Tree from Array

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


node* buildTreeFromArray(int *a, int s, int e) {
	// base case
	if(s>e) {
		return NULL;
	}

	// recursively call for the left and right half
	int mid = (s+e)/2;
	node* root = new node(a[mid]);
	root->left = buildTreeFromArray(a, s, mid-1);
	root->right = buildTreeFromArray(a, mid+1, e);

	return root;
}

int main() {

	int arr[] = {1,2,3,4,5,6,7};
	int n = sizeof(arr)/sizeof(arr[0]);

	node *root = buildTreeFromArray(arr, 0, n-1);
	bfs(root);

	return 0;
}
