// 1460. Make Two Arrays Equal by Reversing Sub-arrays

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> mp;
        
        for(auto it: target) {
            mp[it]++;
        }
        
        for(auto it: arr) {
            if(mp.count(it))
                mp[it]--;
        }
        
        for(auto [num, cnt]: mp) {
            if(cnt > 0) {
                return false;
            }
        }
        
        return true;
    }
};

// 1461. Check If a String Contains All Binary Codes of Size K
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length();
        
        if(k > n) {
            return false;
        }
        
        set<string> unq;
        
        for(int i=0; i<n-k+1; i++) {
            string binary = s.substr(i, k);
            unq.insert(binary);
        }
        
        int all_binary = pow(2, k);
        if(unq.size() == all_binary) return true;
        return false;
    }
};

// 1462. Course Schedule IV

class Solution {
    void dfs(int node, vector<bool> &vis, vector<int> adj[]) {
        vis[node] = true;
        
        for(auto it: adj[node]) {
            if(!vis[it]) {
                dfs(it, vis, adj);
            }
        }
    }
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& preq, vector<vector<int>>& queries) {
        vector<int> adj[numCourses];
        
        for(int i=0; i<preq.size(); i++) {
            int u = preq[i][0];
            int v = preq[i][1];
            
            adj[u].push_back(v);
        }
        
        vector<bool> res;
        
        for(int i=0; i<queries.size(); i++) {
            int src = queries[i][0];
            int dest = queries[i][1];
            
            vector<bool> vis(numCourses, false);
            
            dfs(src, vis, adj);
            
            res.push_back(vis[dest]);
        }
        
        return res;
    }
};


// 1463. Cherry Pickup II

class Solution {
    int t[71][71][71];
    int m;
    int n;
    int solve(vector<vector<int>> &grid, int r, int c1, int c2) {
        if(r == m) {
            return 0;
        }
        
        if(t[r][c1][c2] != -1) {
            return t[r][c1][c2];
        }
        
        int res = 0;
        
        for(int i=-1; i<=1; i++) {
            for(int j=-1; j<=1; j++) {
                int nc1 = c1 + i;
                int nc2 = c2 + j;
                
                if(nc1 < 0 or nc2 < 0 or nc1>= n or nc2 >= n) continue;
                res = max(res, solve(grid, r+1, nc1, nc2));
            }
        }
                          
        int cherries = c1 == c2 ? grid[r][c1] : grid[r][c1] + grid[r][c2];
        return t[r][c1][c2] = cherries + res;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        memset(t, -1, sizeof(t));
        
        return solve(grid, 0, 0, n-1);
    }
};