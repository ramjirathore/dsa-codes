// PROBLEM - 

// You are given an m x n grid where each cell can have one of three values:

// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

// LINK - https://leetcode.com/problems/rotting-oranges/


// BFS using set - O(n*m) time and space
// Find fresh and rotten ones first
// Then make fresh oranges near rotten ones, rotten!
// Store these rotten ones now and remove them from fresh
// Now start from these rotten ones
// If any time we couldn't affect any orange => its impossible
// Otherwise just the time goes as it is

typedef pair<int,int> pi;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        set<pi> rotten; // to store which are rotten initially
        set<pi> fresh; // to store which ones are fresh
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) {
                    fresh.insert({i, j});
                } else if(grid[i][j] == 2) {
                    rotten.insert({i, j});
                }
            }
        }
        
        int minutes = 0;
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; 
        
        while(fresh.size()) {
            set<pi> infected; // to store which ones become infected this time
            
            // try to infect fresh ones with rotten ones
            for(auto [i, j]: rotten) {
                for(auto dir: directions) {
                    int nextI = i + dir[0];
                    int nextJ = j + dir[1];
                    
                    // next orange near to this rotten one
                    pi nextDir = {nextI, nextJ};
                    
                    // if next one is fresh then make it rotten
                    // hence remove from fresh ones and add into infected ones
                    if(fresh.count(nextDir)) {
                        fresh.erase(nextDir);
                        infected.insert(nextDir);
                    }
                }
            }
            
            // if we couldn't infect any this time this means its not possible
            if(infected.size() == 0) {
                return -1;
            }
            
            // update the rotten ones
            rotten = infected;
            
            // up the minute
            minutes++;
        }
        
        return minutes;
        
    }
};


// Simple queue based BFS - O(n*m) time and space
// Find total oranges and store all rotten oranges
// Now do bfs and for each rotten orange infect the near ones and push them in queue
// Count the no. of rotten oranges everytime and increment days 
// In the end if the count == total then return days else -1

typedef pair<int,int> pi;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<int, int>> rotten;
        int total = 0;
        
        // calculate total oranges and 
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] != 0) total++;
                if(grid[i][j] == 2) rotten.push({i, j});
            }
        }
        
        int minutes = 0;
        int count = 0;
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; 
        
        // do bfs
        while(!rotten.empty()) {
            int k = rotten.size();
            count += k; // count the no. of rotten ones
            
            while(k--) {
                auto [x, y] = rotten.front();
                rotten.pop();
                
                for(auto dir: directions) {
                    int nx = x + dir[0];
                    int ny = y + dir[1];

                    // if out of boundary or already rotten then skip this
                    if(nx < 0 or ny < 0 or nx >= m or ny >= n or grid[nx][ny] != 1) continue;
                    grid[nx][ny] = 2; // make next one rotten
                    rotten.push({nx, ny}); // add it into rotten ones
                }
            }
            
            // if there are some rotten then increment minutes
            if(!rotten.empty()) minutes++;            
        }
        
        // if total present have become rotten then return time else -1
        return total == count ? minutes : -1;
    }
};