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

// BRUTE FORCE - O(n2) time and O(n) space
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


// Optimized solution - O(n) time and O(n) space
class Pair {
    public: 
        int h;
        int d;
};

class Solution {
public:
    Pair dmt(TreeNode *root) {
        Pair p;
        if(root == NULL) {
            p.h = -1;
            p.d = 0;
            return p;
        }
        
        Pair ld = dmt(root->left);
        Pair rd = dmt(root->right);
        p.h = max(ld.h, rd.h) + 1;
        
        int rootd = ld.h + rd.h + 2;
        p.d = max(rootd, max(ld.d, rd.d));
        
        return p;            
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        return dmt(root).d;
    }
};

// Another Optimal - DFS O(n) time solution
class Solution {
public:
    int diameter;
    int dfs(TreeNode *root) {
        if(root == NULL) return 0;
        
        int leftHeight = dfs(root->left);
        int rightHeight = dfs(root->right);
        
        diameter = max(diameter, leftHeight+rightHeight);
        
        return max(leftHeight, rightHeight) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        diameter = 0;
        dfs(root);
        return diameter;
    }
};