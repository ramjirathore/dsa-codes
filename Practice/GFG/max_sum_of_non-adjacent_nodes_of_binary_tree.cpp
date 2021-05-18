// PROBLEM - 
// Given a binary tree with a value associated with each node,
// we need to choose a subset of these nodes such that sum of chosen nodes is maximum under a constraint that no two chosen node in subset should be directly connected that is, 
// if we have taken a node in our sum then we can’t take its any children in consideration and vice versa. 

//LINK - https://practice.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1
//Solution - https://www.youtube.com/watch?v=ZdIrKO7gqok

// Approach - O(2^N) time and O(N) space
// When you include node ->
//  you can't take its children thus you can take only its grandchildren(root->left->left, root->left->right, root->right->left, root->right->right)
// When you exclude node ->
//  then you can take its children (because they're not adjacent obviously) ie root->left , root->right

// Optimization - O(N) time and space
// But by just doing this the complexity will reach 2^N
// If we draw recursion then we can see we recalculate max sum for each node many times
// thus we can store it or ie do memoization basically to speed up program by storing results
// Thus this will make worst case time to O(n) and O(n) space (due to the map)



//Function to return the maximum sum of non-adjacent nodes.
unordered_map<Node*, int> dp;
int getMaxSum(Node *root) 
{
    if(root == NULL) {
        return 0;
    }
    
    if(dp[root]) {
        return dp[root];
    }

    int inc = root->data;
    // if including then call its grandchildren
    if(root->left) {
        
        inc += getMaxSum(root->left->left);
        inc += getMaxSum(root->left->right);
    }
    
    if(root->right) {
        inc += getMaxSum(root->right->left);
        inc += getMaxSum(root->right->right);
    }
    
    // if excluding then call its children
    int exc = getMaxSum(root->left) + getMaxSum(root->right);
    
    dp[root] = max(inc, exc);
    
    return dp[root];
}