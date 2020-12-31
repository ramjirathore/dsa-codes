// PROBLEM - 

// Given an array nums of size n, return the majority element.
// The majority element is the element that appears more than ⌊n / 2⌋ times. 
// You may assume that the majority element always exists in the array.

// Link - https://leetcode.com/problems/majority-element-ii/
// Solution - https://www.youtube.com/watch?v=yDbkQd9t2ig&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=16

// BRUTE FORCE - O(n*n) time and O(1) space
// Traverse the whole array for each element
// Find its count and if its greater n/3
// Return the array of elements fulfilling above conditions
// No need of code :P


// BETTER - O(n) time (freq array) or O(nlogn) time (hashmap) | O(n) space
// Create a hashmap and find count of each element
// traverse map and check if condition satisfies
// return the answer array

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        
        for(auto it: nums) {
            mp[it]++;
        }
        
        vector<int> ans;
        
        for(auto cnt: mp) {
            if(cnt.second > nums.size()/3) {
                ans.push_back(cnt.first);
            }
        }
        
        return ans;
    }
};

