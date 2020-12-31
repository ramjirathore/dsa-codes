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



// OPTIMAL - (Boyer moore's voting algorithm) - O(n) time | O(1) space
// There can be at most two majority elements
// so find candidate1 and candidate2 assuming them initially -1
// and their counts as 0
// Traverse whole array and check if curr == num1 if yes then inc cnt 1
// else check curr == num2 if yes then inc cnt2
// if cnt1 == 0 then set num1 = cur and cnt1 = 1 
// similarly for cnt2
// else dec both cnt

// confirm if they occur > n/3 by retraversing
// return ans array

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candt1 = -1, candt2 = -1, count1 = 0, count2 = 0;
        int sz = nums.size();
        
        // find candidates
        for(int i=0; i<sz; i++) {
            if(nums[i] == candt1) count1++;
            
            else if(nums[i] == candt2) count2++;
            
            else if(count1 == 0) {
                candt1 = nums[i];
                count1 = 1;
            }
            
            else if(count2 == 0) {
                candt2 = nums[i];
                count2 = 1;
            }
            
            else {
                count1--;
                count2--;
            }
        }
        
        vector<int> ans;
        count1 = count2 = 0;
        
        // confirm if candidates are majority element
        for(auto num: nums) {
            if(num == candt1) count1++;
            if(num == candt2) count2++;
        }
        
        // if candidate1 is then push it
        if(count1 > sz/3) ans.push_back(candt1);
        
        // if candidate2 is then push it 
        if(count2 > sz/3 && candt1!=candt2) ans.push_back(candt2);
        
        return ans;
    }
};