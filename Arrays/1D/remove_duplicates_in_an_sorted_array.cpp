// PROBLEM - 

// 26. Remove Duplicates from Sorted Array

// LINK - https://leetcode.com/problems/remove-duplicates-from-sorted-array/

// O(n) time and O(n) space
// Find all unique elements using set
// Then just put these ones into original
// Set size if the size of unique elements return it
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 0) {
            return 0;
        }
        
        set<int> unq;
        
        for(auto &it: nums) {
            unq.insert(it);
        }
        
        
        int j = 0;
        for(auto &val: unq) {
            nums[j++] = val;
        }
        
        return unq.size();
    }
};

// O(n) time and O(1) space
// Iterate and find next non matching element
// and putting it to next duplicate of i
// Increment i and repeat
// i+1 is the new array size of unique elements

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 0) {
            return 0;
        }
        
        int i = 0;
        
        for(int j=1; j<n; j++) {
            if(nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }
        
        return i+1;
    }
};