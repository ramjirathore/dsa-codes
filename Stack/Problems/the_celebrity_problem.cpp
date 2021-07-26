// PROBLEM - 

// A celebrity is a person who is known to all but does not know anyone at a party. 
// If you go to a party of N people, find if there is a celebrity in the party or not.
// A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j  
// is set to 1 it means ith person knows jth person. Here M[i][i] will always be 0.

// LINK - https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1#


// Prove that there cannot be two celebrities - 
// Assume if 2 is celebrity then 2 is known by everyone and he doesn't everyone
// For another celebrity to exist he must be known by everyone but since 2 is already celebrity
// He doesn't know this new person => hence proved by contradiction that there will be only 1 celebrity
// Not more than that



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


// BETTER (Stack Approach) - O(N) time and O(N) space
// For this approach we will use given information
// If i knows j then for sure i is not celebrity but j could be
// Similarly, If j knows i then for j is not celebrity but i could be

// So using we find our potential candidate 
// But we need to confirm it (Why ? since we did not all other i js for this candidate)
// So if anyone knows our candidate or our candidate know anyonne then he is not celeb
// Otherwise for sure he is

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> s;
        
        for(int i=0; i<n; i++) {
            s.push(i);
        }
        
        while(s.size() >= 2) { 
            // choose two persons 
            int i = s.top();
            s.pop();
            
            int j = s.top();
            s.pop();
            
            if(M[i][j] == 1) {
                // i knows j => i not celeb j could be 
                // so push it back
                s.push(j);
            } else {
                // i doesn't know j => j is not celeb i could be
                // so push it back
                s.push(i);
            }
        }
        
        if(s.empty()) { // if stack empty means no celeb
            return -1;
        }
        
        int candidate = s.top();
        s.pop();
        
        
        // Verfiy if its celebrity or not
        for(int i=0; i<n; i++) {
            // if candidate is not himself
            // and if he candidate know i or i doesn't candidate then for sure he is not celeb
            if(candidate != i and (M[candidate][i] == 1 or M[i][candidate] == 0)) {
                return -1;
            }
        }
        
        // else he is return the candidate
        return candidate;
    }
};



// OPTIMAL (Assume an candidate) - O(N) time and O(1) space
// Assume i is and celebrity and then just verify it
// Verification - (If i is not the candidate itself and) If candidate knows anyone or somemone doesn't know candidate
// Then he is not celeb for sure
// Else he/she is!

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        int candidate = 0;
        
        for(int i=0; i<n; i++) {
            if(M[candidate][i] == 1) { 
                // if candidate know i 
                // then i is candidate
                candidate = i;
            }
        }
        
        
        // Verfiy if its celebrity or not
        for(int i=0; i<n; i++) {
            // if candidate is not himself
            // and if he candidate know i or i doesn't candidate then for sure he is not celeb
            if(candidate != i and (M[candidate][i] == 1 or M[i][candidate] == 0)) {
                return -1;
            }
        }
        
        // else he is return the candidate
        return candidate;
    }
};
