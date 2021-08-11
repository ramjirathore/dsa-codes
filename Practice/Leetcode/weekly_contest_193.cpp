
// 1480. Running Sum of 1d Array
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for(int i=1; i<nums.size(); i++) {
            nums[i] += nums[i-1];
        }
        
        return nums;
    }
};


// 1481. Least Number of Unique Integers after K Removals
typedef pair<int,int> pi;

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        
        for(auto it: arr) {
            mp[it]++;
        }
        
        
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        
        for(auto [el, count]: mp) {
            pq.push({count, el});
        }
        
        while(k > 0) {
            auto &[cnt, el] = pq.top();
            if(cnt > k) break;
            k -= cnt;
            pq.pop();
        }
        
        return pq.size();
    }
};


// 1482. Minimum Number of Days to Make m Bouquets
// O(nlog(maxDays)) time and O(1) space

class Solution {
    int possibleBoquets(vector<int> bloomDay, int day, int k) {
        int totalBoquets = 0;
        int flowersCollected = 0;
        
        for(auto val: bloomDay) {
            if(val <= day) {
                flowersCollected ++;
            } else {
                flowersCollected = 0;
            }
            
            if(flowersCollected == k) {
                totalBoquets++;
                flowersCollected = 0;
            }
        } 
        
        return totalBoquets;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(m*k > bloomDay.size()) return -1;
        
        int mx = 0;
        int mn = 1e9+1;
        
        for(auto it: bloomDay) {
            mx = max(mx, it);
            mn = min(mn, it);
        }
        
        while(mn < mx) {
            int mid = mn + (mx - mn) / 2;
            
            if(possibleBoquets(bloomDay, mid, k) < m) {
                mn = mid + 1;
            } else {
                mx = mid;
            }
        }
        
        return mn;
    }
};


// 1483. Kth Ancestor of a Tree Node
// O(log(max(K)) * number of node) for initilizing(prepare)
// O(log(K)) for getKthAncestor (N times query).

class TreeAncestor {
    vector<vector<int>> par;
public:
    TreeAncestor(int n, vector<int>& parent) {
        par.resize(20, vector<int>(n, -1));
        
        // 2^0
        for(int i=0; i<n; i++) {
            par[0][i] = parent[i]; 
        }
      
        // 2^i
        for(int i=1; i<20; i++) {
            for(int node = 0; node < n; node++) {
                int parent_node = par[i-1][node];
                if(parent_node != -1) {
                    par[i][node] = par[i-1][parent_node];
                } 
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int i=0; i<20; i++) {
            if(k & (1 << i)) {
                node = par[i][node];
                
                if(node == -1) return -1;
            }
        }
        
        return node;
    }
};
