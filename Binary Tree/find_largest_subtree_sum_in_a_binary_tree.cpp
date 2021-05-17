// Problem - 
// Given a binary tree, task is to find subtree with maximum sum in tree.

// Link - https://www.geeksforgeeks.org/find-largest-subtree-sum-tree/#

// Approach - O(n) time and O(n) space
// Do post order traversal of the binary tree. 
// At every node, find left subtree value and right subtree value recursively. 
// The value of subtree rooted at current node is equal to sum of current node value, left node subtree sum and right node subtree sum. 
// Compare current subtree sum with overall maximum subtree sum so far.

int lSubSum(Node *root, int &ans) {
	if(root == NULL) {
		return 0;
	}


	int lSum = lSubSum(root->left, ans);
	int rSum = lSubSum(root->right, ans);

	int currSum = root->data + lSum + rSum;

	ans = max(ans, currSum);

	return currSum;
}

int findLargestSubtreeSum(Node *root) {
	if(root == NULL) {
		return 0;
	}

	int ans = INT_MIN;

	lSubSum(root, ans);

	return ans;
}
