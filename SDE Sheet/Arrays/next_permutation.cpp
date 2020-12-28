// Problem - 

// Implement next permutation, which rearranges numbers into the lexicographically
// next greater permutation of numbers.
// If such an arrangement is not possible, it must rearrange it as the lowest possible order 
// (i.e., sorted in ascending order).
// The replacement must be in place and use only constant extra memory.

// Link - https://leetcode.com/problems/next-permutation/
// Solution - https://www.youtube.com/watch?v=LuLCLgMElus&t=320s
// Suggested Solution to understand Intution (imp) - https://www.youtube.com/watch?v=quAS1iydq7U&t=506s



// Brute Force - O(n!*n) time and O(n) space
// Find all possible permutations
// Linearly search for the next permutation


// Optimal - O(n) time and O(1) space
// Requires an indepth analysis of the intution

// Basically , you need to know how permutations are generated
// Watch suggested video

// Optimal - O(n) time and O(1) space

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // find decreasing subarray
        int j = nums.size() - 2;
        
        while(j>=0 && nums[j] >= nums[j+1]) {
            --j;
        }
        
        // Checking if its not last permutation
        if( j < 0) { // if yes then simply reverse since answer is the first permutation
            reverse(nums.begin() , nums.end());
        } else {
            // else find and swap the current element & the next greatest element from it

            int i = nums.size() - 1;
            while(i>=0 && nums[j] >= nums[i]) {
                --i;
            } 
            swap(nums[j], nums[i]);
            
            // reverse the remaining after j index (since it was last permutation..see intution to understand this)
            reverse(nums.begin() +j+1, nums.end());
        }
        
    }
};