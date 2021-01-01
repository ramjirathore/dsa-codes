// PROBLEM -

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