// PROBLEM - 

// A celebrity is a person who is known to all but does not know anyone at a party. 
// If you go to a party of N people, find if there is a celebrity in the party or not.
// A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j  
// is set to 1 it means ith person knows jth person. Here M[i][i] will always be 0.

// LINK - https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1#


// Simple graph approach - O(N*N) time and O(N) space
// Find indeg and outdegree
// For a celeb outdeg must be zero and indeg must be n-1
class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        vector<int> indeg(n, 0);
        vector<int> outdeg(n, 0);
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(M[i][j]) {
                    outdeg[i]++;
                    indeg[j]++;
                }
            }
        }
        
        for(int i=0; i<n; i++) {
            if(indeg[i] == n-1 and outdeg[i] == 0) {
                return i;
            }
        }
        
        return -1;
    }
};