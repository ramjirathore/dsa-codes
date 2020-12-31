// PROBLEM - 

// Given an array nums of size n, return the majority element.
// The majority element is the element that appears more than ⌊n / 2⌋ times. 
// You may assume that the majority element always exists in the array.

// Link - https://leetcode.com/problems/majority-element/
// Solution - https://www.youtube.com/watch?v=AoX3BPWNnoE

// BRUTE FORCE - O(n*n) time and O(1) space
// Traverse the whole array for each element
// Find its count and if its greater than floor of n/2
// Return the element 




// BETTER - O(n) time if freq array used or O(nlogn) time if used hashmap |  O(n) space
// Use a hashmap(precisely unordered map) to count occurences of each element
// if it any point the count becomes more than floor of n/2 
// Return the element
class Solution {
public:
    int majorityElement(vector<int>& nums) {
       unordered_map<int, int> mp;

	for (auto it : nums) {
		mp[it]++;
	}

	for (auto item : mp) {
		if (item.second > nums.size() / 2) {
			return item.first;
		}
	}
    
        return -1;
    }
};


// OPTIMAL (Moore's Voting Algorithm) - O(n) time and O(1) space 

// Intution - Since maj element exists more than n/2 times
// so if we cancel every other occurence of another element with this element
// We will get this element in the end!

// Assume first element as candidate majority element and count as one
// Increase count by 1 if next element is same else decrease
// if at any step count becomes zero update candidate as current element |  also reset count to 1
// Repeat this till array end

// Return candidate since it is majority


class Solution {
public:
    int majorityElement(vector<int>& nums) {
    int majorIndex = 0; // assuming major as first element
	int count = 1;

	// Find candidate ie v[majorIndex]
	for (int i = 1; i < nums.size(); i++) {
		if(nums[i] == nums[majorIndex]) {
			count++;
		} else {
			count --;
		}

		if(count == 0) {
			majorIndex = i;
			count = 1;
		}
	}
    return nums[majorIndex];
    }
};