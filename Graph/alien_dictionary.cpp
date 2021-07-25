// PROBLEM - 

// Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary. 
// Find the order of characters in the alien language.

// Note: Many orders may be possible for a particular test case, thus you may return any valid order and output will be 1 if the order of string returned by the function is correct else 0 denoting incorrect string returned.
 
// Your Task:
// You don't need to read or print anything. 
// Your task is to complete the function findOrder() which takes  the string array dict[], its size N and the integer K as input parameter and returns a string denoting the order of characters in the alien language. 



// LINK - https://practice.geeksforgeeks.org/problems/alien-dictionary/1#


// SOLUTION - O(N+K) time and O(K) space
// Traverse and compare two strings at a time until they encouter a character which is different
// Why ? because when you lexicographically sort the strings then the lower character is before
// We use this information and form a edge between char u -> char v (Since we are given sorted list)
// Create graph and just find the topological sort of edges
// The order will be sorted order of characters in Alien dictionary.

// #PeaceOut

class Solution{
    stack<char> s;
    vector<bool> vis;
    void dfs(int node, vector<int> adj[]) {
        vis[node] = true;
        
        for(auto it: adj[node]) {
            if(!vis[it]) {
                dfs(it, adj);
            }
        }
        
        s.push(node + 'a');
    }
    public:
    string findOrder(string dict[], int N, int K) {
        vis.resize(K, false);
        
        vector<int> adj[K];
        
        for(int idx=1; idx<N; idx++) {
            string word1 = dict[idx-1];
            string word2 = dict[idx];
            
            int i=0; 
            int j=0;
            
            while(i < word1.length() and j < word2.length()) {
                if(word1[i] != word2[j]) {
                    adj[word1[i] - 'a'].push_back(word2[j] - 'a');
                    break;
                }
                
                i++;
                j++;
            }
        
        }
        
        for(int i=0; i<K; i++) {
            if(!vis[i]) {
                dfs(i, adj);
            }
        }
        
        string topo;
        while(!s.empty()) {
            topo += s.top();
            s.pop();
        }
        
        return topo;
    }
};