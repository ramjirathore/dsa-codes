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




// OPTIMAL: O(n) time and O(n) space
// 1.Put all elements in hashSet
// 2.Traverse each element and check if curr - 1 exists in array 
// 3. If yes then move forward
// 4. Else (this means you have reached minimal of a sequence) now search curr+1 and check if it exists,
// maintain the count and update the max count when the curr doesn't exist

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        set<int> hashSet; 
        for(int x: nums) {
            hashSet.insert(x);
        }
            
        int longestStreak = 0;
        
        for(int val: nums) {
            if(!hashSet.count(val-1)) {
                int currentNum = val;
                int currentStreak = 1;
                while(hashSet.count(currentNum + 1)) {
                    currentStreak++;
                    currentNum++;
                }
                longestStreak = max(longestStreak, currentStreak);
            }
        }
        
        return longestStreak;
        
    }
};

