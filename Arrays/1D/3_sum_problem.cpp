// PROBLEM - 

// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] 
// such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
// Notice that the solution set must not contain duplicate triplets.

// LINK - https://leetcode.com/problems/3sum/


// BRUTE FORCE - O(n3) time and O(n) space
// pick two values and search linearly in the remaining array everytime



// OPTIMAL APPROACH - O(n*n) time and O(n) space
// sorting is necessary
// Fix one number and approach the rest like 2 sum problem
// Skip duplicates for i, l, r 

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // sort the array
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> res;
        int n = nums.size();
        
        
        for(int i=0; i<n-2; i++) {
            // skipping duplicate i
            if(i > 0 and nums[i] == nums[i-1]) continue;
            
            // additional condition just to optimize
            // if curr nums is > 0 => all values after this are > 0 => can't make 3 sum to zero
            if(nums[i] > 0) break;
            
            int sum = 0 - nums[i];
            
            int l = i+1;
            int r = n-1;
            
            while(l < r) {
                int curr_sum = nums[l] + nums[r];
                if(curr_sum < sum) {
                    l++;
                } else if(curr_sum > sum) {
                    r--;
                } else {
                    res.push_back(vector<int>{nums[i], nums[l], nums[r]});
                    
                    // now skip duplicates
                    while(l < r and nums[l] == nums[l+1]) l++;
                    while(l < r and nums[r] == nums[r-1]) r--;
                    
                    // move l and r pointers
                    l++;
                    r--;
                }
            }
        }
        
        
        return res;
    }
};