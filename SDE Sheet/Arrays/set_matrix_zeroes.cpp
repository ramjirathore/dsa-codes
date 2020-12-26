// PROBLEM - 

// Given an m x n matrix. If an element is 0, set its entire row and column to 0. Do it in-place.
// Follow up:
// A straight forward solution using O(mn) space is probably a bad idea.
// A simple improvement uses O(m + n) space, but still not the best solution.
// Could you devise a constant space solution?


// Link - https://leetcode.com/problems/set-matrix-zeroes/
// Solution - https://www.youtube.com/watch?v=M65xBewcqcI&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=7


// BRUTE FORCE - O((n*m)*(n+m)) time and O(1) space 
// Set all values in row and column to INT_MIN (or something which doesn't comes in constraints)
// where zero comes
// Traverse again and set zero wherever our set values lies.

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
       int row = matrix.size(), col = matrix[0].size(); 
        
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(matrix[i][j] == 0) {
                    for(int k=0; k<row; k++) {
                        if(matrix[i][k]!=0)
                            matrix[i][k] = INT_MIN;
                    }
                    for(int k=0; k<col; k++) {
                        if(matrix[k][j]!=0)
                            matrix[k][j] = INT_MIN;
                    }
                }
            }
        }
        
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(matrix[i][j] == INT_MIN) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};



// BETTER - O((n*m)) time and O(n+m) space
// Take two auxillary arrays row and col
// set corresponding index to zero in required aux array 
// whenever a val is zero.
// Traverse then and put that whole col/row if zero found at that index in any aux array

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
       int row = matrix.size(), col = matrix[0].size(); 
        vector<int> rows(row, -1); 
        vector<int> cols(col, -1);
        
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(matrix[i][j] == 0) {
                    rows[i] = 0;
                    cols[j] = 0;
                }
            }
        }
        
       for(int i=0; i<row; i++) {
           for(int j = 0; j<col; j++) {
               if(rows[i] == 0 || cols[j] == 0) {
                   matrix[i][j] = 0;
               }
           }
       }
    }
};





// OPTIMAL - O((n*m)) time and O(1) space
// Improving the better approach 
// we will use the given 2D array for storing the aux array
// col[0] and row[0] 
// plus imp -  we will use col = true and a[0][0]
// so that both col[0] and row[0] don't simultaneouosly become zero when one gets affected

// Then we will set values to zero acc while iterating in reverse (#imp)


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
       int row = matrix.size(), col = matrix[0].size(); 
        bool col0 = true;
        
        for(int i=0; i<row; i++) {
            if(matrix[i][0] == 0) col0 = false; // if any zero in first col 
            for(int j=1; j<col; j++) {
                if(matrix[i][j] == 0) {
                  matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        
       for(int i=row-1; i>=0; i--) {
           for(int j = col-1; j>=1; j--) {
               if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                   matrix[i][j] = 0;
               }
           }
         if(col0 == false) matrix[i][0] = 0;
       }
    }
};