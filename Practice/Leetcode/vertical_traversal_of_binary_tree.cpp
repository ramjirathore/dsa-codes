//PROBLEM -
// Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

// For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

// The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

// Return the vertical order traversal of the binary tree.


// LINK - https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
// SOLUTION VIDEO - https://www.youtube.com/watch?v=kqHNP6NTzME

// CODE - 


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

// We basically are storing "vertical columns" as rows here and then the "horizonatl rows of binary tree"
// as cols here and each of this col is also a map which has row index, and a multiset to store nodes of same level.

// then the algo is simply just do dfs and keep storing col and row and nodes in this data structure
// then iterate this to return the answer

// TC- O(logn* logn * logn * N)
class Solution {
public:
    map<int, map<int, multiset<int>>> mp;
    void vOrder(TreeNode* root, int row, int col) {
        if(root == NULL) {
            return;
        }
        
        mp[col][row].insert(root->val);
        vOrder(root->left, row+1, col-1);
        vOrder(root->right, row+1, col+1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> v;
        vOrder(root, 0, 0);
        
        for(auto row: mp) {
            vector<int> temp;
            for(auto col: row.second) {
                for(auto it: col.second) {
                    temp.push_back(it);
                }
            }
            v.push_back(temp);
        }
        
        return v;
    }
};