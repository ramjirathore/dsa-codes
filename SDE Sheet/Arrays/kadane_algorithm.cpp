// Problem -

// Given an integer array nums, find the contiguous subarray (containing at least one number) 
// which has the largest sum and return its sum.

// Link - https://leetcode.com/problems/maximum-subarray/
// Solution - https://www.youtube.com/watch?v=w_KEocd__20&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=5



// BRUTE FORCE - O(n*n*n) time and O(1) space
// Traverse all possible subarrays 
// then find the max sum
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    	int n = nums.size();

		int maxSum = INT_MIN;

		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				int sum = 0;
				for (int k = i; k <= j; k++) {
					sum += nums[k];
				}

				maxSum = max(sum, maxSum);
			}
		}

		return maxSum;
    }
};


// BETTER - O(n*n) time and O(1) space
// The third loop can be removed since we are adding one element everytime in 2nd loop
// so we can calc sum there and check

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      int n = nums.size();

		int maxSum = INT_MIN;

		for (int i = 0; i < n; i++) {
            int sum = 0;
			for (int j = i; j < n; j++) {
				sum += nums[j];
				maxSum = max(sum, maxSum);
			}
		}

		return maxSum;
    }
};

// Alternatively, we can have a prefix sum array - O(n*n) time and O(n) space
// This approach is discussed in ARRAYS (course section) 





// OPTIMAL - (Kadane's Algorithm) - O(n) time and O(1) space
// Intution - We want maxSum so whenever our sum becomes negative 
// and if we add it to next positive val it will always dec the sum
// so we reset it to zero

// Traverse the array find sum
// If sum becomes negative (i.e. < 0) at any point reset sum to 0
// Update maxSum if sum becomes greater than it


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cSum = 0, maxSum= INT_MIN;
        
        for(auto it: nums) {
            cSum += it;
            
            maxSum = max(cSum, maxSum);
            
            if(cSum < 0) {
                cSum = 0;
            }
            
        }
        return maxSum;
    }
};