// PROBLEM - 
// Given an array of 0s and 1s. Find the length of the largest subarray with equal number of 0s and 1s.

// LINK - https://practice.geeksforgeeks.org/problems/largest-subarray-of-0s-and-1s/1/

// BRUTE FORCE - O(n^2) time and O(1) space
// We add -1 instead of 0 and 1 in place of 1, then we just check for all subarrays sum to be zero 
// because when sum is zero => the zeroes and ones are equal in count

int findSubArray(int arr[], int n)
{
    int sum = 0;
    int maxsize = -1, startindex;

    // Pick a starting point as i
    for (int i = 0; i < n - 1; i++) {
        sum = (arr[i] == 0) ? -1 : 1;

        // Consider all subarrays starting from i
        for (int j = i + 1; j < n; j++) {
            (arr[j] == 0) ? (sum += -1) : (sum += 1);

            // If this is a 0 sum subarray, then
            // compare it with maximum size subarray
            // calculated so far
            if (sum == 0 && maxsize < j - i + 1) {
                maxsize = j - i + 1;
                startindex = i;
            }
        }
    }
    if (maxsize == -1)
        cout << "No such subarray";
    else
        cout << startindex << " to "
             << startindex + maxsize - 1;

    return maxsize;
}


// OPTIMAL - O(n) time and space
// We will use the same technique to find largest array where sum is zero
// How? Just replace 0 by -1 and then find the length whenever the sum is found again.
// Why this works? Because when the sum is same this means there are equal no.s of zeroes and one's

int maxLen(int arr[], int N){
   // sum and index
   unordered_map<int, int> mp;
   mp[0] = -1;
   
   int res = 0;
   int sum = 0;
   
   for(int i=0; i<N; i++) {
       sum += arr[i] == 0 ? -1: 1;
       
       if(mp.count(sum)) {
           res = max(res, i - mp[sum]);
       } else {
           mp[sum] = i; 
       }
   }
   
   return res;
}