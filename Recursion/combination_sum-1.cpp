// PROBLEM - 

//39. Combination Sum

// LINK - https://leetcode.com/problems/combination-sum/

// O(2^target * k) time and O(k * length of combinations) space
// you can choose one element multiple time or not choose it

class Solution {
    vector<vector<int>> res;
    void solve(vector<int> &cand, int i, int target, vector<int> &sub) {
        if(i == cand.size()) {
            if(target == 0) {
                res.push_back(sub);
            }
            return;
        }
        
        if(cand[i] <= target) {
            sub.push_back(cand[i]);
            solve(cand, i, target - cand[i], sub);
            sub.pop_back();
        }
        
        solve(cand, i+1, target, sub);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& cand, int target) {
        sort(cand.begin(), cand.end());
        
        vector<int> sub;
        solve(cand, 0, target, sub);
        
        return res;
    }
};