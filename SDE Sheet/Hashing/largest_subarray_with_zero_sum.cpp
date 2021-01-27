// PROBLEM - 

// Given an array having both positive and negative integers. 
// The task is to compute the length of the largest subarray with sum 0.

// Link - https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1
// Solution - https://www.youtube.com/watch?v=xmguZ6GbatA&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=22


// BRUTE FORCE - O(n^3) time and O(1) space
// Simply check for all the subarrays where sum becomes 0
// Constantly update the max length of such array 
// return the answer in the end 
// Simple code, write it yourself:P



// OPTIMAL - O(nLogn) time and O(n) space
// n due to traversal and logn for worst case hit in checking hashmap

// Best is to watch video to understand clearly intution
int maxLen(int A[], int n)
{
    unordered_map<int, int> mp;
    
    
    int sum = 0;
    int maxi = 0;
    
    for(int i=0; i<n; i++) {
        sum += A[i];
       
        // if till now sum is zero then length will be current index + 1
        if(sum == 0) {
            maxi = i + 1;
        } 
        else {
            // else check if sum exists and then means all the elements after that sum is making sum same
            // which implies that this patch sums up to zero, so update max length
            if(mp.find(sum) != mp.end()) {
                maxi = max(maxi, i - mp[sum]);
            } else {
                // else if sum is not there in hash table then add it 
                mp[sum] = i;
            }
        }
    }
    
    return maxi;
}
