// PROBLEM - (#GOOGLE INTERVIEW)

// A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
// The robot can only move either down or right at any point in time. 
// The robot is trying to reach the bottom-right corner of the grid.
// How many possible unique paths are there?

// Link - https://leetcode.com/problems/unique-paths/
// Solution - https://www.youtube.com/watch?v=t_f0nwwdg5o&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=17



// BRUTE FORCE - O(2^n) time and O(2^n) space
// since we're trying all possible solutions
// and storing stack space for the same

class Solution {
public:
    int countPath(int i, int j, int m, int n) {
        if(i == m && j == n) return 1;
        if(i > m || j > n)  return 0;
        
        int rightPath = countPath(i,j+1,m,n);
        int downPath = countPath(i+1,j,m,n);
        
        return rightPath+downPath;
    }
    int uniquePaths(int m, int n) {
                
        return countPath(0,0,m-1,n-1);
        
    }
};


// BETTER -(Dynamic Programming Approach) - O(n*m) time and O(n*m) space

// #very important to understand ->

// In Brute force, We observe that we reach same (i,j) call multiple times
// if we analyse then we see there are two states [i] and [j]
// which are always changing in recursive calls
// max i could be m and max j could be n 

// So we prepare of dp hashtable of size[i][j] having -1 in it initially
// whenever we reach a recursive we store the result 
// and next time if the same i j recursive call is made 
// we return the answer from dp hashtable

//  - thus no. of at max calls could be - m*n
// - space m*n for hashtable and also same  for stack space

class Solution {
public:
    int countPath(int i, int j, int m, int n, vector<vector<int>> &dp) {
        if(i == m && j == n) return 1;
        if(i > m || j > n)  return 0;
        
        // checking (i,j) recursive call has happened before
        if(dp[i][j]!=-1) return dp[i][j]; // if yes simply return ans
        
        int rightPath = countPath(i,j+1,m,n,dp);
        int downPath = countPath(i+1,j,m,n,dp);
        
        // store it in dp hashtable
        return dp[i][j] = rightPath + downPath;
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return countPath(0,0,m-1,n-1, dp);
        
    }
};


// OPTIMAL -(Combinatorics Approach) - O(n) or O(m) time and O(1) space

// ## Just observe with an example understand it superbly.
// for ex take m =2, n=3 then try watching writing down all the paths.
// You'll see something

// so we get unique paths as 
// R R B
// R B R
// B R R

// Observation1 -> Total paths are: 3 ...(m+n-2 ..explained below)
// Observation2 -> 
// from above example
// No. of right directions we take (in any case) = 2 ...(n-1)
// No. of down directions we take (in any case) = 1 ...(m-1) 
// So total paths we take =  (m-1 + n-1) which is (m+n-2)
// => total path always are m+n-2


// Ultimately we need to fill three boxes -> _ _ _
// if we choose our two rightward directions = 3C2 = 3
// or if we choose our one downward direction = 3C1 = 3

// #imp - we can choose only either right or down at one time because rest automatically gets fixed
class Solution {
public:    
    int uniquePaths(int m, int n) {
        int N = (m+n-2); // Total no. of paths
        
        // choosing downward direction 
        int r = (m-1); // (rightward could also be chosen in its place)
        
        // calculating N(C)r
        double res = 1;
        for(int i=1; i<=r; i++) {
            // if writing res * = ...don't forget to typecast
            res = res * (N-r+i) / i;
        }
        
        return (int)res;
    }
};