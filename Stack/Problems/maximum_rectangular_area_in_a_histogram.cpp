// PROBLEM - 

// Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number
// of contiguous bars. For simplicity, assume that all bars have the same width and the width is 1 unit.

// LINK - https://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1#

// BRUTE FORCE - O(N*N) time and O(1) space
// Find nearest smallest index on left and right for each number
// This difference will give you the width and thus area
// Update max area

class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
       
        // Now we know the left smallest and right smallest element for each element
        // We can now get the width using these
        long long max_area = 1;
        
        for(int i=0; i<n; i++) {
            // find nearest smallest on right
            int right = i;  
            while(right < n and arr[right] >= arr[i]) {
                right++;
            }
            
            // fint nearest smallest on left
            int left = i;  
            while(left >= 0 and arr[left] >= arr[i]) {
                left--;
            }
            
            long long width = right - (left + 1);
    
            max_area = max(max_area, arr[i] * width);
        }
       
        return max_area;
    }
};

