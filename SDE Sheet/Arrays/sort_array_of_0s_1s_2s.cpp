// PROBLEM -

// Given an array nums with n objects colored red, white, or blue, sort them in-place 
// so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
// Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

// Link - https://leetcode.com/problems/sort-colors/
// Solution - https://www.youtube.com/watch?v=oaVa-9wmpns&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=2




// Brute force - O(NlogN) time and O(1) space
// => Sort the array simply
class Solution {
public:
    void sortColors(vector<int>& nums) {
    	sort(nums.begin(), nums.end());
   }
};





// Better - O(N)time (exact O(2N)) and O(N) space
// => Use counting sort 
// then replace 0s, 1s and 2s using their count in original array

// PS: code can be written in better way
class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> count(3, 0);
        for(auto x: nums) {
            count[x]++;
        }
        
        int j = 0;
        for(int i=0; i<nums.size(); i++) {       
            if(count[j] > 0) {
                nums[i] = j;
                count[j]--;
            } else {
                j++;
                i--;
            }
        }
    }
};







// Optimal - Use Dutch National Flag Algorithm
// make three paritions (set low and mid to start and high at end)
// 0 to low -1 -> all 0s
// low to mid-1 -> all 1s
// high+1 .. -> all 2s

// such that
// arr[mid] is -> 
// 0 => swap low and mid values.. then inc low and mid pointers  
// 1 => inc mid pointer simply
// 2 => swap mid and high values.. then dec high pointer			

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Dutch National Flag Algorithm
        
        // [0 to low-1] -> all 0s lie
        // [low to mid-1] -> all 1s lie
        // [high+1 ... ] -> all 2s lie
        
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;
        
        while(mid<=high) {
            switch(nums[mid]) {
                case 0: 
                    swap(nums[low], nums[mid]);
                    low++; mid++;
                    break;
                case 1: 
                    mid++;
                    break;
                case 2: 
                    swap(nums[mid], nums[high]);
                    high--;
                    break;
            }
        }
    }
};