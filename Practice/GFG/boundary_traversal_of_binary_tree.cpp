// PROBLEM - 
// Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 

// Left boundary nodes: defined as the path from the root to the left-most node ie- the leaf node you could reach when you always travel preferring the left subtree over the right subtree. 
// Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.
// Reverse right boundary nodes: defined as the path from the right-most node to the root. The right-most node is the leaf node you could reach when you always travel preferring the right subtree over the left subtree. Exclude the root from this as it was already included in the traversal of left boundary nodes.
// Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary. 


// LINK - https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1#


// Solution - O(n) time and O(n) space
// Intution - As we can see there are three parts
// Left boundary, Leaves, Right boundary
// So we can find them separately and then push in a vector
// Also notice the direction in which we are traversing
// For left bdry - we are top to bottom => we will push nodes in before going deep into recursion
// For right bdry - we are going bottom to top => push after coming out of recursion 
// For leaves - while in between
// same code can be seen in code

class Solution {
public:
    void LeftBdry(Node* root, vector<int> &v) {
        if(root == NULL) {
            return;
        }
        
        if(root->left) {
            v.push_back(root->data);
            LeftBdry(root->left, v);
        } else if(root->right) {
            v.push_back(root->data);
            LeftBdry(root->right, v);
        }
    }
    
    void Leaf(Node* root, vector<int> &v) {
        if(root == NULL) {
            return;
        }
        
        Leaf(root->left, v);
        if(!root->left and !root->right) {
            v.push_back(root->data);
        }
        
        Leaf(root->right, v);
    }
    
    void RightBdry(Node* root, vector<int> &v) {
        if(root == NULL) {
            return;
        }
        
        if(root->right) {
            RightBdry(root->right, v);
            v.push_back(root->data);
        } else if(root->left) {
            RightBdry(root->left, v);
            v.push_back(root->data);
        }
    }

    vector <int> printBoundary(Node *root)
    {
        vector<int> ans;
      
        ans.push_back(root->data);
        LeftBdry(root->left, ans);
        if(root->left or root->right) { // to make sure that if only root is there we do not push it again
            Leaf(root, ans);
        }
        RightBdry(root->right,ans);
        
        return ans;
    }
};
