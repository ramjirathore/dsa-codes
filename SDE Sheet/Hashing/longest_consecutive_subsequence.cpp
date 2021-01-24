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


