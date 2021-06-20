// PROBLEM - (This is a Parent Problem - 0/1 Knapsack)

// You are given weights and values of N items, put these items in a knapsack of capacity W 
// to get the maximum total value in the knapsack. Note that we have only one quantity of each item.
// In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and 
// weights associated with N items respectively. Also given an integer W which represents knapsack capacity, 
// find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. 
// You cannot break an item, either pick the complete item or don’t pick it (0-1 property)


// BRUTE FORCE - O(2^N) time and O(1) extra space
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


// OPTIMAL - O(N*W) time and space
// We can break this question into subproblems and store the answer everytime in an matrix (dp)
// When we need it then we can fetch it from dp matrix
// Few changes in above code will lead us to TOP DOWN Approach / MEMOIZATION 

// The size of matrix will be N+1, W+1
int dp[1001][1001];

class Solution
{
    public:
    Solution() { // initialize the matrix with -1
        memset(dp, -1, sizeof(dp));
    }
    
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // no elements or no capacity    
       if(n==0 or W==0) {
           return 0;
       }
       
       if(dp[n][W] != -1) {
           return dp[n][W];
       }
       
       if(wt[n-1] <= W) {
           // either include it or don't
           return dp[n][W] = max(val[n-1] + knapSack(W-wt[n-1], wt, val, n-1), knapSack(W, wt, val, n-1));
       } else if(wt[n-1] > W) {
           // can't include since its larger than capacity
           return dp[n][W] = knapSack(W, wt, val, n-1);
       }
    }
};


// OPTIMAL - O(N*W) time and space
// From the (first) recursive code we will generate the bottom up approach / tabulation method which is iterative.


// (Derived from the recursive code)
int t[1001][1001];

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // initialising the first row and columns
       for(int i=0; i<n; i++) {
           t[i][0] = 0;
       }
       
       for(int j=0; j<W; j++) {
           t[0][j] = 0;
       }
       
       
       // for remaining columns to find subproblems solution 
       // i,j-> n,W 
       for(int i=1; i<n+1; i++) {
           for(int j=1; j<W+1; j++) {
               if(wt[i-1] <= j) { // if we can make a choice ie either select or not select
                   t[i][j] = max(val[i-1] + t[i-1][j-wt[i-1]], t[i-1][j]);
               } else { // we can't select the item at all
                   t[i][j] = t[i-1][j];
               }
           }
       }
       
       // the last cell will have the answer
       return t[n][W];
    }
};


