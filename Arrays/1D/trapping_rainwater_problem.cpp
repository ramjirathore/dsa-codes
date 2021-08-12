// PROBLEM -

// 42. Trapping Rain Water

// Given n non-negative integers representing an elevation map where the width of each bar is 1, 
// compute how much water it can trap after raining.

// LINK - https://leetcode.com/problems/trapping-rain-water/

// BRUTE FORCE - O(n*n) time and O(1) space
// At each index find left max and right max
// then calculate how much water can be store for that index

// BETTER APPROACH (Pref max and suff max approach) -  O(n) time and O(n) space
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        vector<int> prefmax(n, 0);
        vector<int> suffmax(n, 0);
        
        // find prefix max array
        prefmax[0] = max(prefmax[0], height[0]);
        for(int i=1; i<n; i++) {
            prefmax[i] = max(prefmax[i-1], height[i]);
        }
        
        // find suffix max array
        suffmax[n-1] = max(suffmax[n-1], height[n-1]);
        for(int j=n-2; j>=0; j--) {
            suffmax[j] = max(suffmax[j+1], height[j]);
        }
        
        
        int res = 0;  
        // now find the trapped water for each index
        // using these two arrays
        for(int i=0; i<n; i++) {
            // min of prefmax and suffmax will give height till water live
            // and subtract the height the elevation (width will be 1 only)
            res += min(prefmax[i], suffmax[i]) - height[i];
        }
        
        return res;
    }
};


// OPTIMAL (Two pointer approach)- O(n) time and O(1) space
// We need to left max and right max for each index, so that we can know how much water can be stored at that index
// Maintain leftmax and rightmax, left and right pointers
// which compares left with right and tells which is higher
// then just update res using leftmax for left
// and for right using right max for right

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        int maxleft = 0;
        int maxright = 0;
        
        int left = 0;
        int right = n - 1;
        
        int res = 0;
        
        while(left <= right) {
            // This surely means there is a right wall greater/equal then left => water can be stored till curr left
            if(height[left] <= height[right]) {
                if(height[left] > maxleft) { // now if we find more height curr left, update
                    // obviously its more height so no point of updating res
                    maxleft = height[left];
                } else { // else just update res using left max boundary
                    res += maxleft - height[left];
                }
                left++;
            } else { // this surely means there is a left wall greater/equal then right
                // => water can be stored curr right
                if(height[right] > maxright) { // now if we find more height than curr right, update
                    // obviously its more height so no point of updating res
                    maxright = height[right];
                } else { // else just update res using right max boundary
                    res += maxright - height[right];
                }
                right--;
            }
        }
        
        return res;
    }
};