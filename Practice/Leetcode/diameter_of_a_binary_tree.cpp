/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// BRUTE FORCE - 
class Solution {
public:
    int height(TreeNode *root) {
       
        if(root == NULL) {
            return 0;
        }
        
        int lHeight = height(root->left);
        int rHeight = height(root->right);
        
        return max(lHeight, rHeight) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
      
        if(root == NULL) {
            return 0;
        }
        
        int hl = height(root->left);
        int hr = height(root->right);
        
        int rootDiameter = hl + hr;
        
        int leftDiameter = diameterOfBinaryTree(root->left);
        int rightDiameter = diameterOfBinaryTree(root->right);
        
        
        return max(rootDiameter, max(leftDiameter, rightDiameter));
        
    }
};