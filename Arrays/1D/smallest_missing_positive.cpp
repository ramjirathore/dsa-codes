// PROBLEM -

// 41. First Missing Positive

// Given an unsorted integer array nums, return the smallest missing positive integer.
// You must implement an algorithm that runs in O(n) time and uses constant extra space.

// LINK - https://leetcode.com/problems/first-missing-positive/

// O(n) time and O(1) space
// we basically will turn our array into a boolean array to find if a number is present or not
// all numbers as negative using the curent num as index
// then we check if some num is positive then we return index + 1
// else n + 1
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        for(int i=0; i<n; i++) {
            if(nums[i] <= 0) {
                nums[i] = n+1;
            }
        }
        
        for(int i=0; i<n; i++) {
            int idx = abs(nums[i]);
            
            if(idx - 1 < n and nums[idx-1] > 0) {
                nums[idx-1] = -nums[idx-1];
            }
        }
        
        for(int i=0; i<n; i++) {
            if(nums[i] > 0) {
                return i+1;
            }
        }
        
        return n+1;
    }
};


// Another solution -
// O(n) time and O(1) space
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
      
        // place the positive number at its correct position
        // ignore negative number and number greater than n
        int i = 0;
        while(i < n) {
            // current becomes index
            // and we swap until the each element reaches its position
            if(nums[i] > 0 and nums[i] - 1 < n and nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            } else {
                i++;
            }
        }
        
        // the number which is not at its correct position is our answer
        for(int i=0; i<n; i++) {
            if(i+1 != nums[i]) {
                return i+1;
            }
        }
        
        // if all at correct
        // then smallest positive is n+1
        return n+1;
    }
};