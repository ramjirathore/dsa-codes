// PROBLEM - (Asked in Amazon)
// Print all k-sum paths in a binary tree
// A binary tree and a number k are given. Print every path in the tree with sum of the nodes in the path as k.
// A path can start from any node and end at any node and must be downward only, 
// i.e. they need not be root node and leaf node; and negative numbers can also be there in the tree

// LINK - https://www.geeksforgeeks.org/print-k-sum-paths-binary-tree/


// Approach - O(n*h*h) time and O(height) space
// Notice how it is mention that we need only downward paths (this is a very useful information)
// So the approach is to traverse all nodes using dfs and keep inserting values in a vector 
// and at every node we need to traverse the vector from behind (since only downward paths are there)
// and for each traversal we need to sum_so_far == targetSum if yes then print that path
// By this way we will print all paths which exist from a certain to this node

void printKPathUtil(Node *root, vector<int>& path, int targetSum)

    // empty node
    if (!root)
        return;
  
    // add current node to the path
    path.push_back(root->data);
  
    // check if there's any k sum path
    // in the left sub-tree.
    printKPathUtil(root->left, path, k);
  
    // check if there's any k sum path
    // in the right sub-tree.
    printKPathUtil(root->right, path, k);
  
    // check if there's any k sum path that
    // terminates at this node
    // Traverse the entire path as
    // there can be negative elements too
    int f = 0;
    for (int j=path.size()-1; j>=0; j--)
    {
        f += path[j];
  
        // If path sum is same as targetSum, print the path
        if (f == k) {
        	for (int j=i; j<v.size(); j++)
      			cout << v[j] << " ";
  			cout << endl;
        }
    }
  
    // Remove the current element from the path
    path.pop_back();
}

void printKPath(Node *root, int k)
{
    vector<int> path;
    printKPathUtil(root, path, k);
}