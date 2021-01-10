// PROBLEM - 

// Given an array nums of n integers and an integer target, 
// are there elements a, b, c, and d in nums such that a + b + c + d = target? 
// Find all unique quadruplets in the array which gives the sum of target.

// Notice that the solution set must not contain duplicate quadruplets.

// Example - 
// Input: nums = [1,0,-1,0,-2,2], target = 0
// Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]


// Link - https://leetcode.com/problems/4sum/
// Solution - https://www.youtube.com/watch?v=4ggF3tXIAp0&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=20



// BRUTE FORCE - O(n3logn) time and O(1) space
// Sort the array -> O(nlogn)
// Then take four pointers i j k 
// i -> 0 to n   ..   j ->i+1 to n  k-> i to j        -> O(n3) time
// Do binary search for the remaining value in the right part  -> O(logn) time

// Thus total time -> O(n3logn) + O(nlogn)
// and we generally don't consider the returning answer space so -> O(1) space

// code coming in sometime...



// OPTIMAL - O(N3) time and O(1) space
// 1. Sort the array
// 2. Take two pointers i and j, follow below steps
// - start j from i+1 and also have left and right pointers
// - mark left next to j and right at end of array
// - check for remaining sum ie target - val[i] - v[j]
// - that val[left]+ va[right] == rem sum, if not move left forward or right backward accordingly
// - making sure that next value is not same, if yes then skip it (this avoids repeating quadreplets)
// - push the quadreplets to answer (take HASHSET for unique quadruplets storing)
// - skip repeats for i and j too

// Code will bring more clarity :)
// Also generally we don't count the space we need to return
// Hence O(1) space

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        
        if(nums.empty()) return ans;
        
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                int target_2 = target - nums[i] - nums[j];
                
                // left replaced by front
                int front = j+1;
                int back = n-1;
                
                while(front < back) {
                    int twoSum = nums[front] + nums[back];
                    
                    if(twoSum < target_2) front++;
                    else if(twoSum > target_2) back--;
                    else {
                        vector<int> quadruplet(4, 0);
                        quadruplet[0] = nums[i];
                        quadruplet[1] = nums[j];
                        quadruplet[2] = nums[front];
                        quadruplet[3] = nums[back];
                        
                        ans.push_back(quadruplet);
                        
                        // Processing the duplicates of number 3
                        while(front < back && nums[front] == quadruplet[2]) ++front;
                        
                        // Processing the duplicates of number 4
                        while(front < back && nums[back] == quadruplet[3]) --back;
                    }
                }
                // Processing the duplicates of number 2
                while(j+1<n && nums[j+1] == nums[j]) ++j;
            }
            // Processing the duplicates of number 1
            while(i+1<n && nums[i+1] == nums[i]) ++i;
        }
        
        return ans;
    }
}; 
