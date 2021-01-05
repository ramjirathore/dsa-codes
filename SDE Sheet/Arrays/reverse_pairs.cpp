// PROBLEM - 

// Given an array nums, we call (i, j) an important reverse pair if i < j and nums[i] > 2*nums[j].
// You need to return the number of important reverse pairs in the given array.

// Link - https://leetcode.com/problems/reverse-pairs/
// Solution - https://www.youtube.com/watch?v=S6rsAlj_iB4&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=18

// BRUTE FORCE - O(n*n) time and O(1) space
// Traverse the element for each element
// and For each element check in its in right half
// which satisfies the condition and increase the count

// no need to code :P



// OPTIMAL - O(nlogn) time and O(n) space
// Explanation - watch the video
// Intution - same approach as no. of inversions

class Solution {
public:
    int merge(vector<int> &arr, int low, int mid, int high) {
            int j = mid+1;
            int count = 0;

            for(int i=low; i<=mid; i++) {
                while(j<=high && arr[i] > 2LL * arr[j]) {
                    j++;
                }
                count += (j-(mid+1));
            }


            vector<int> temp;
            int i = low;
            j=mid+1;

            while(i<=mid && j<=high) {
                if(arr[i]<= arr[j]) {
                    temp.push_back(arr[i++]);
                } else {
                    temp.push_back(arr[j++]);
                }
            }

            while(i<=mid) {
                temp.push_back(arr[i++]);                
            }


            while(j<=high) {
                temp.push_back(arr[j++]);                            
            }

            for(int i=low; i<=high; i++) {
                arr[i] = temp[i-low]; 
            }

            return count;
    }
    
    int reversePairCount(vector<int> &nums, int s, int e) {
        
        if(s>=e) {
            return 0;
        }
        
        int mid = (s+e)/2;
            
        int x = reversePairCount(nums, s, mid);
        int y = reversePairCount(nums, mid+1, e);
            
        int z = merge(nums, s, mid, e);
            
        return x+y+z;
    }
    
    int reversePairs(vector<int>& nums) {
       return reversePairCount(nums, 0, nums.size() - 1);
    }
};