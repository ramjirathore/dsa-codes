// PROBLEM -

// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
// There is only one duplicate number in nums, return this duplicate number.

// Link - https://leetcode.com/problems/find-the-duplicate-number/
// Solution - https://www.youtube.com/watch?v=32Ll35mhWg0&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=1



// Brute force - O(N*N) time and O(1) space
// => Sort the array and then compare adjacent elements
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
    	for(int i=1; i<nums.size(); i++) {
		    if(nums[i] == nums[i-1]) {
			    return nums[i];
		    }
	    }
        return -1;
    }
};



// Better Solution - O(N) time and O(N) space
// Create a hashmap and check the count

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
    	for(auto x: nums) {
	    	mp[x]++;
		    if(mp[x]==2) {
			    return x;
		    }
	    }
        return -1;
    }
};


// Optimal - O(n) time and O(1) space
// Use Floyd's cycle detection and removal approach
// phase 1 - fast and slow meet 1st time
// phase 2 - fast and slow now moves at SAME speed 
// 			 put slow - at head
//			 continue fast - from intersection point
// => they meet at (cycle joint) duplicate 

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow!=fast);
        
        slow = nums[0];
        
        while(slow!=fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }
};