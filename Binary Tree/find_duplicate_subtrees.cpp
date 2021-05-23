// PROBLEM-
// Given the root of a binary tree, return all duplicate subtrees.
// For each kind of duplicate subtrees, you only need to return the root node of any one of them.
// Two trees are duplicate if they have the same structure with the same node values

// LINK - https://leetcode.com/problems/find-duplicate-subtrees/
// Solution - https://www.youtube.com/watch?v=nxHBg7hm0rs&t=345s


// Approach -[ O(nlogn) time and O(n) space ](not sure)
// So basically we traverse the whole tree and if node is null then return some delimiter like X
// return left and right subtree and create a new string consisting of current root data + lsub + rsub
// make sure you add the ',' or any similar separtor so that when same no.s come then we know
// for ex - 222XXX and 222XXX should've different as nodes value are 2 and 22

class Solution {
public:
    map<string, int> mp;
    vector<TreeNode*> ans;
    string getDups(TreeNode* root) {
        if(!root) {
            return "X";
        }

        string left = getDups(root->left);
        string right = getDups(root->right);

        
        string temp = to_string(root->val) + "," + left + right;

        mp[temp]++;

        if(mp[temp] == 2) {
            ans.push_back(root);
        }

        return temp;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        getDups(root);
        return ans;
    }
};