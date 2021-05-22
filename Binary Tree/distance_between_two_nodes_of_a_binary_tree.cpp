// PROBLEM -
// Given a binary tree and two node values your task is to find the minimum distance between them.

// LINK - https://practice.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1#
// Solution- https://www.youtube.com/watch?v=6DraIPN_0no (also some part of editorial)

// Approach - 
// O(n) time and O(h) space

// We can see that there must a kind of joining node between these nodes which is the link between these nodes
// and after thinking we can see that it is LCA
// so basically if we found out LCA and then find dist of a from Lca and dist of b from LCA
// Then the answer is just the sum of these two.

Node* findLCA(Node* root, int a, int b) {
    if(root == NULL) {
        return NULL;
    }
    
    // Found the key return the address
    if(root->data == a or root->data == b) {
        return root;
    }
    
    
    Node* lsub = findLCA(root->left, a, b);
    Node* rsub = findLCA(root->right, a, b);
    
    // found both keys this means this is the root
    if(lsub and rsub) {
        return root;
    }
    
    // didn't find any key
    if(!lsub and !rsub) {
        return NULL;
    }
    
    // found one
    return lsub ? lsub : rsub;
    
}

int findLevel(Node* root, int lvl, int k) {
    if(root == NULL) {
        return -1;
    }
    
    if(root->data == k) {
        return lvl;
    }
    
    
    int lSub = findLevel(root->left, lvl+1, k);
    
    // if couldn't found on leftside
    if(lSub == -1) {
        return findLevel(root->right, lvl+1, k);
    }
    
    return lSub;
    
}

int findDist(Node* root, int a, int b) {
    
   Node* lca = findLCA(root, a, b);
   
   int daLCA = findLevel(lca, 0, a);
   int dbLCA = findLevel(lca, 0, b);
   
   return daLCA + dbLCA;
}