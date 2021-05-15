// PROBLEM - Given a Binary Tree, print the diagonal traversal of the binary tree.
// Consider lines of slope -1 passing between nodes. Given a Binary Tree, print all diagonal elements in a binary tree belonging to same line.


// LINK - https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1
// SOLUTION - 
// (Recursive) - https://www.youtube.com/watch?v=JVRsHnQPBHY
// (Iterative) - https://www.youtube.com/watch?v=6iAMy7fw6M4&t=0s


// Recursive - O(n) time and O(n) space
// (Intution)
// Give no.s to diagonals starting from 0 (ie root)
// since left diagonals are to be chosen => all right children of a node will lie in same diagonal
// thus same d number
// and all left children will be always in next diagonal.
// store each diagonal as key and node data as values in that key.
// Since we traverse all nodes thus O(n) time and stack space is used to store these nodes thus O(n) space

map<int, vector<int>> mp;
void diagTraversal(Node* root, int d) {
    if(root == NULL) {
        return;
    }
    
    
    mp[d].push_back(root->data);
    
    // if you go left child then diagonal changes 
    diagTraversal(root->left, d+1);
    // diagonal remains the same on right child
    diagTraversal(root->right, d);

}

vector<int> diagonal(Node *root)
{
    vector<int> ans;
    diagTraversal(root, 0);
    
    for(auto diag: mp) {
        for(auto vals: diag.second) {
            ans.push_back(vals);
        }
    }
    
    return ans;
}


// Iterative - O(n) time and < O(n) space
// we set curr as front of queue
// we print current root data 
// then we push left child to queue if it exists
// then we move current to its right child (since they are in same diagonal)
// we do this until curr is not null
vector<int> diagonal(Node *root)
{
    vector<int> ans;
    queue<Node*> q;
    
    q.push(root);
    
    while(!q.empty()) {
        Node* curr = q.front();
        q.pop();
        
        while(curr) {
            ans.push_back(curr->data);
            if(curr->left) {
                q.push(curr->left);
            }
            curr = curr->right;
        }
    }
    return ans;
}

