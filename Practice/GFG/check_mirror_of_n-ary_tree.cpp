// PROBLEM - 
// Given two n-ary trees. Check if they are mirror images of each other or not. 
// You are also given e denoting the number of edges in both trees, and two arrays, A[] and B[]. 
// Each array has 2*e space separated values u,v denoting an edge from u to v for the both trees.


// Link - https://practice.geeksforgeeks.org/problems/check-mirror-in-n-ary-tree1528/1#
// Solution - Read the editorial 

// Intution - 
// create a stack and queue and push each node's children 
// why stack and queue?
// Because invert the children 
// thus we can compare both stack and queue

class Solution {
  public:
    
    bool checkMirror(vector<stack<int>> &tree1, vector<queue<int>> &tree2, int sz) {
        for(int i=0; i<sz; i++) {
            if (!tree1[i].size() && !tree2[i].size()) continue;
            
            stack<int> s = tree1[i];
            queue<int> q = tree2[i];
            
            while(!s.empty() && !q.empty()) {
                int front = q.front();
                int top = s.top();
                
                if(front != top) {
                    return false;
                }
                
                s.pop();
                q.pop();
            }
        }
        
        return true;
    }
  
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        vector<stack<int>> tree1(e+1);
        vector<queue<int>> tree2(e+1);

        int i = 0;
        int j = 0;
        while(i<(2*e-1)) {
            tree1[A[i]].push(A[i+1]);
            i += 2;
        }
        
        while(j<(2*e-1)) {
            tree2[B[j]].push(B[j+1]);
            j += 2;
        }
        
        return checkMirror(tree1, tree2, tree1.size());
    }
};