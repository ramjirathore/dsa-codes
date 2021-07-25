// PROBLEM -


// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
// You may assume all four edges of the grid are all surrounded by water

// LINK - https://leetcode.com/problems/number-of-islands/

// Simple dfs to find connected component - O(N*M) time and space
class Solution {
vector<pair<int, int>> dir;
    int vis[502][502];
    int m;
    int n;
    
    void dfs(vector<vector<char>> &grid, int i, int j) {
       
        vis[i][j] = 1;
        
        for(auto it: dir) {
            int x = it.first + i;
            int y = it.second + j;
            
            if(x >=0 and y >=0 and x < m and y < n) {
                if(!vis[x][y] and grid[x][y] == '1')
                    dfs(grid, x, y);
            }
        }
    }
    public:
    //Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {

        dir = {{0,-1}, {0, 1}, {-1, 0}, {1, 0}};
        memset(vis, 0, sizeof(vis));
        
        m = grid.size();
        n = grid[0].size();
         
        
         
        int islands = 0;
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == '1' and !vis[i][j]) {
                    islands++;
                    dfs(grid, i, j);
                }
            }
        }
        
        return islands;
    }
};