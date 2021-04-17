// PROBLEM - 
// Given an array, rotate the array to the right by k steps, where k is non-negative.

// LINK - https://leetcode.com/problems/rotate-array/


// SOLUTION -

// BRUTE FORCE - O(n) time and O(n) space
// Create two arrays
// one of lenght k and other of n-k
// Store one half in k and other in n-k
// then rewrite both halfs (according to given condition) to the original array


// OPTIMAL - O(n) time and O(1) space
// Reverse the whole array
// Then reverse till K length
// Then reverse from k to end
// Also do k = k % arrSize (see constraints)

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        k = k % nums.size();
        
        reverse(nums.begin(), nums.end());
        reverse(nums.begin()+k, nums.end());
        reverse(nums.begin(), nums.begin()+k);
    }
};
