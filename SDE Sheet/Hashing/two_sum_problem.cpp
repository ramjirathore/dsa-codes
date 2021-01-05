// PROBLEM - 

// Given an array of integers nums and an integer target, 
// return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.

// Link - https://leetcode.com/problems/two-sum/submissions/
// Solution - https://www.youtube.com/watch?v=dRUpbt8vHpo&list=PLgUwDviBIf0rVwua0kKYlsS_ik_1lyVK_&index=1



// BRUTE FORCE - O(n*n) time and O(1) space
// Traverse for each element and check in right its half for target sum
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

// Better - (Two pass iteration) - O(n) time and O(n) space 
// Create a hashmap and store the number and its index
// Traverse again and check if (target - curr num) is there and its not the current index onlu
// if yes then return boths' indices
// else at the end return empty array
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        
        for(int i=0; i<nums.size(); i++) {
            mp[nums[i]] = i; 
        }
        
        for(int i=0; i<nums.size(); i++) {
            auto it = mp.find(target-nums[i]);
            if( it!= mp.end() && it->second !=i) {
                return {i, it->second};
            }
        }
        
        return {};
    }
};


// Optimal - (one pass iteration) - O(n) time and O(n) space 
// Create a hashmap and then start traversing
// check if (target - curr num) is there 
// if yes then return boths' indices
// else store the current val and index
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
      
        for(int i=0; i<nums.size(); i++) {
            
            if( mp.find(target-nums[i])!= mp.end()) {
                return {mp[target-nums[i]], i};
            }
            
            mp[nums[i]] = i;    
        }
        
        return {};
    }
};