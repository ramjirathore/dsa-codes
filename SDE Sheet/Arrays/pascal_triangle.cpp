// Problem - 

// Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.
// EX -
// Input: 5
// Output:
// [
//      [1],
//     [1,1],
//    [1,2,1],
//   [1,3,3,1],
//  [1,4,6,4,1]
// ]


// Link - https://leetcode.com/problems/pascals-triangle/
// Solution - https://www.youtube.com/watch?v=6FLvhQjZqvM&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=8


// Optimal - O(n*n) time and O(1) space
// All outside values are 1 so initilaze them as 1
// Inner values = j-1 val prev row + j prev row


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal(numRows);
        
        for(int i=0; i<numRows; i++) {
            pascal[i].resize(i+1);
            pascal[i][0] = pascal[i][i] = 1;
            
            for(int j=1; j<i; j++) {
                pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j]; 
            }
                    
        }
        
        return pascal;
    }
}; 