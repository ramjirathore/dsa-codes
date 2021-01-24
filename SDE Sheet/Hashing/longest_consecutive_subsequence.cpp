// PROBLEM - 

// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

// Link: https://leetcode.com/problems/longest-consecutive-sequence/
// Solution : https://www.youtube.com/watch?v=qgizvmgeyUM&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=21


// BRUTE FORCE: O(n3) time and O(1) space
// We try to basically count as high as possible 
// considering each number in array
// we store the max in longest streak

class Solution {
    public:
    bool arrayContains(vector<int> arr, int num) {
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == num) {
                return true;
            }
        }

        return false;
    }
    int longestConsecutive(vector<int> &nums) {
        int longestStreak = 0;

        for (int num : nums) {
            int currentNum = num;
            int currentStreak = 1;

            while (arrayContains(nums, currentNum + 1)) {
                currentNum += 1;
                currentStreak += 1;
            }

            longestStreak = max(longestStreak, currentStreak);
        }

        return longestStreak;
    }
}

// BETTER: O(nlogn) time and O(1)(if we are allowed to modify array) or O(n) (we will store copy) space
// Sort the array - O(nlogn)
// Traverse the array and find longestStreak 
// if currentStreak breaks in between then reset the currentStreak to 1

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.size() == 0)  return 0;
        
        sort(nums.begin(), nums.end());

        int longestStreak = 1;
        int currentStreak = 1;
        
        for(int i = 1; i<nums.size(); i++) {
            if (nums[i] != nums[i-1]) {
                if (nums[i] == nums[i-1] + 1) {
                    currentStreak += 1;
                }
                else {
                    longestStreak = max(longestStreak, currentStreak);
                    currentStreak = 1;
                }
            }
        }
        
        return max(longestStreak, currentStreak);
        
    }
};




