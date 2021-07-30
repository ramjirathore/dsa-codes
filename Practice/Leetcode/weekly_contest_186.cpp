// 1422. Maximum Score After Splitting a String

// Count ones then initially
// then while splitting increase zero whenever found
// else decrease ones
// Update max score

class Solution {
public:
    int maxScore(string s) {
        int ones = 0;
        int zero = 0;
        for(auto it: s) {
            if(it == '1') {
                ones++;
            }
        }
        
        int score = 0;
        
        for(int i=0; i<s.length()-1; i++) {
            if(s[i] == '0') {
                zero++;
            } else {
                ones--;
            }
            
            score = max(score, zero + ones);
        }
        
        return score;
        
    }
};

//1423. Maximum Points You Can Obtain from Cards

// O(n) time and O(k) space

// While choosing
// we can choose only from start or end
// So possiblities are either we choose 
// for k = 3
// 0 from left and all 3 from right
// 1 from left and 2 from right
// 2 from left and 3 from right
// 3 from left and 0 from right

// so create these arrays of sum choices
// and then we just have to find maximum

class Solution {
public:
    int maxScore(vector<int>& points, int k) {
        int n = points.size();
        
        vector<int> left = {0};
        vector<int> right = {0};
        
        // 0 1 3 6
        // 0 1 7 12
        
        for(int i=0; i<k; i++) {
            left.push_back(left.back() + points[i]);
            right.push_back(right.back() + points[n-i-1]);
        }
    
        int res = 0;
        int sz = left.size();
    
        for(int i=0; i<sz; i++) {
            // cout<<left[i]<<" "<<right[sz-i-1]<<endl;
            res = max(res, left[i] + right[sz-i-1]);
        }
        
        return res;
        
    }
};



// 1424. Diagonal Traverse II

// Approach 1- (Priyansh's)
// Observation based - O(n) time and O(n) space
// you can observe this all those in diagonal have a same i+j
// We can use this information to store them first them using map
// Then print it

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        map<int, vector<int>> mp;
                
        for(int i=0; i<nums.size(); i++) {
            for(int j=0; j<nums[i].size(); j++) {
                mp[i+j].push_back(nums[i][j]);
            }
        }
        
        vector<int> res;
        
        // traverse each i+j in reverse order
        for(auto it: mp) {
            int m = it.second.size();
            for(int j=m-1; j>=0; j--) {
                res.push_back(it.second[j]);
            }
            cout<<endl;
        }
        
        return res;
    }
};


// Approach 2-
// Bfs solution - O(N) time and O(N) space
// maintain the vis using a map 

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        
       
        queue<pair<int, int>> q;
        q.push({0, 0});
        
        map<pair<int,int>, bool> vis;
        vis[{0, 0}] = true;
        
        vector<int> trav;
        
        
        while(!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            
            
            trav.push_back(nums[i][j]);
            
            int n = nums.size();
            int m = nums[i].size();
            
            // check if its not the last row also or already visited
            // check if you can go into next row or not 
            if(i + 1 < n and j < nums[i+1].size() and !vis[{i+1, j}]) { 
                vis[{i+1, j}] = true;
                q.push({i+1, j});
            }
            
            // check if its not last column or already visited
            if(j + 1 < m and !vis[{i, j+1}]) {
                vis[{i, j+1}] = true;
                q.push({i, j+1});
            }
        }
        
        
        return trav;
    }
};

// Approach 3 -
// O(n) time and O(n) space
// bfs + observation

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        
       
        queue<pair<int, int>> q;
        q.push({0, 0});
        
        
        vector<int> trav;
        
        while(!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            
            trav.push_back(nums[i][j]);
            
            int n = nums.size();
            int m = nums[i].size();
            
            if(i + 1 < n and j == 0) { // this j == 0 ensures that we push just first column values
                // then we pop out values we'll always have to go right diagonal by diagonal
                q.push({i+1, j});
            }
            
            if(j + 1 < m) {
                q.push({i, j+1});
            }
        }
        
        
        return trav;
    }
};