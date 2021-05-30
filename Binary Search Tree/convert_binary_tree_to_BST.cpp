// PROBLEM - 
// Given a Binary Tree, convert it to Binary Search Tree in such a way that keeps the original structure of Binary Tree intact.
 
// LINK - https://practice.geeksforgeeks.org/problems/binary-tree-to-bst/1#

// Approach - O(nlogn) time and O(n) space
// Its a simple problem just store all the nodes of binary tree using any tree traversal in an array
// Then sort and using this sorted array create BST via recursion.

class Solution{
  public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    void getBTInorder(Node* root, vector<int> &in) {
        if(root == NULL) {
            return;
        }
        
        getBTInorder(root->left, in);
        in.push_back(root->data);
        getBTInorder(root->right, in);
    }
    int index = 0;
    void genBST(Node* &root, vector<int> &in) {
        if(root == NULL) {
            return;
        }
        
        genBST(root->left, in);
        root->data = in[index++];
        genBST(root->right, in);
        
    }
    Node *binaryTreeToBST(Node *root)
    {
        vector<int> inorder;
        getBTInorder(root, inorder);
        sort(inorder.begin(), inorder.end());
        
        
        genBST(root, inorder);
        
        return root;
    }
}; 