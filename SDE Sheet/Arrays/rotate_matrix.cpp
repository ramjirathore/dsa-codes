// PROBLEM - 


// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly.
// DO NOT allocate another 2D matrix and do the rotation.


// Link - https://leetcode.com/problems/rotate-image/
// Solution - https://www.youtube.com/watch?v=Y72QeX0Efxw&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=12



// BRUTE FORCE - O(n*n) time and O(n*n) space
// We take another matrix
// Then We copy each row from last column in second matrix




// OPTIMAL - O(n*n) time and O(1) space
// Intution - we see in final matrix each row is reversal of each column => transpose must be done
// First transpose the matrix
// Then make it mirror image ie reverse every row

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // Transpose
        for(int i=0; i<n; i++) {
            for(int j=0; j<=i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        // Reverse every row 
        for(int i=0; i<n; i++) {
            reverse(matrix[i].begin(),matrix[i].end());
        }
        
    }
};