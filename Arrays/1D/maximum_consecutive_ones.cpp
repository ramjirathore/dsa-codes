// PROBLEM - 

// Given a binary array nums, return the maximum number of consecutive 1's in the array.

// LINK - https://leetcode.com/problems/max-consecutive-ones/submissions/

// Single pass find max ones - O(n) time and O(1) space solution
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ones = 0;
        int count = 0;
        
        for(auto &it: nums) {
            if(it == 0) {
                count = 0;
            } else {
                count++;
            }
            ones = max(ones, count);
        }
        
        return ones;
    }
};