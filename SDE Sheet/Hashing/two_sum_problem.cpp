// PROBLEM - 

// Given an array of integers nums and an integer target, 
// return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.

// Link - https://leetcode.com/problems/two-sum/submissions/
// Solution - https://www.youtube.com/watch?v=dRUpbt8vHpo&list=PLgUwDviBIf0rVwua0kKYlsS_ik_1lyVK_&index=1



// BRUTE FORCE - O(n*n) time and O(1) space
// Traverse for each element and check for target sum
// return the answer

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> index;
        for(int i=0; i<nums.size(); i++) {
            for(int j=i+1; j<nums.size(); j++) {
                if(target-nums[i] == nums[j]) {
                    index.push_back(i);
                    index.push_back(j);
                    break;
                }
            }
        }
        return index;
    }
};


