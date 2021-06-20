// PROBLEM - (This is a Parent Problem - 0/1 Knapsack)

// You are given weights and values of N items, put these items in a knapsack of capacity W 
// to get the maximum total value in the knapsack. Note that we have only one quantity of each item.
// In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and 
// weights associated with N items respectively. Also given an integer W which represents knapsack capacity, 
// find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. 
// You cannot break an item, either pick the complete item or don’t pick it (0-1 property)


// Approach one - O(2^N) time and O(1) extra space
// This is simple recursive approach 
// Basically for each element there are two possibilities -
// 1. Its value is greater than W (capacity) - then we can't take it
// 2. Its value is smaller/equal to W - we can either take it or not take it
// Also if W is zero or size of wt[] is array then we can pick any element => 0

// BUT THIS APPROACH WILL GIVE TLE

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // no elements or no capacity    
       if(n==0 or W==0) {
           return 0;
       }
       
       if(wt[n-1] <= W) {
           // either include it or don't
           return max(val[n-1] + knapSack(W-wt[n-1], wt, val, n-1), knapSack(W, wt, val, n-1));
       } else if(wt[n-1] > W) {
           // can't include since its larger than capacity
           return knapSack(W, wt, val, n-1);
       }
    }
};

