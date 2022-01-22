// PROBLEM - Given an array having both positive and negative integers. 
// The task is to compute the length of the largest subarray with sum 0.

// LINK - https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1


// BRUTE FORCE - O(n^2) time and O(1) space
// Take starting and ending points then calc sum, if sum becomes zero then update max length.
int maxLen(int arr[], int n)
{
    // Initialize result
    int max_len = 0; 

    // Pick a starting point
    for (int i = 0; i < n; i++) {

        // Initialize currr_sum for
        // every starting point
        int curr_sum = 0;

        // try all subarrays starting with 'i'
        for (int j = i; j < n; j++) {
            curr_sum += arr[j];

            // If curr_sum becomes 0, 
            // then update max_len
            // if required
            if (curr_sum == 0)
                max_len = max(max_len, j - i + 1);
        }
    }
    return max_len;
}
