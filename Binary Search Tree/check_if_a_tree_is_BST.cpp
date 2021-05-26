// PROBLEM - 
// Given a binary tree. Check whether it is a BST or not.
// Note: We are considering that BSTs can not contain duplicate Nodes.


// LINK - https://practice.geeksforgeeks.org/problems/check-for-bst/1#
// SOLUTION (Recommended) - https://www.youtube.com/watch?v=maiOCptc3D8


// Mistake - Just checking for root->right->data and root->left->data and thus returning if current's val lies in this won't give
// the correct answer as we are just checking for consecutive nodes
// An counter case/example can be easily produced which fails this solution.

// BRUTE - O(n2) time and O(h) space
// First correct solution is to check for curr val lies between left subtree min and right subtree max
// But this is an O(n2) solution (as we have to traverse all the way long for every node in a skew tree)


// OPTIMAL - #1 O(n) time and O(h) space
// We can thus improve upon brute force by maintaining explicit min and max variables
// We maintain the interval of min max to check if the current root's value lies in this interval
       
bool checkBST(Node *root, int min, int max) {
    if(root == NULL) {
        return true;
	}
        
    int key = root->data;

    return (key > min && key < max && checkBST(root->left, min, key) && checkBST(root->right, key, max));
}
    
    
bool isBST(Node* root) {
    return checkBST(root, INT_MIN, INT_MAX);
}    

// OPTIMAL - #2 O(n) time and O(h) space
// This approach is based on the fact that inorder of binary search tree is sorted
// If it is not then it is not a BST
// But then we have to store in a array => extra space (along with recursion stack space)
// Thus we can maintain a prev variable and keep checking everytime

class Solution
{
    public:
    

    int prev = INT_MIN;
    bool isBST(Node* root) 
    {
        if(root == NULL) {
            return true;
        }
        
        // if left side returns true then only we continue 
        // Also as this call finishes our prev has been set
        if(!isBST(root->left)) {
            return false;
        }
        
        // current value must be greater else return false
        if(root->data <= prev) return false;
        
        prev = root->data;
        
        // Now it depends on the right side
        return isBST(root->right);
    }
};

   