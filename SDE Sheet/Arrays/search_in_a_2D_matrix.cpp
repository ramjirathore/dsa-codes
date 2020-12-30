// PROBLEM - (Leetcode)

// Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row.

// Two variations ->
// Link (Leetcode) - https://leetcode.com/problems/search-a-2d-matrix/
// Link (GFG) - https://www.geeksforgeeks.org/search-in-row-wise-and-column-wise-sorted-matrix/

// Solution - https://www.youtube.com/watch?v=ZYpYur0znng&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=13



// BRUTE FORCE - O(n*m) time and O(1) space
// Traverse the whole matrix and check if the element is present or not
// No need of code :P


// BETTER - O(n*logm) time and O(1) space
// Apply binary search in each row

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0; i<matrix.size(); i++) {
             if(binary_search(matrix[i].begin(), matrix[i].end(), target))  {
                 return true;
             }
        }
        
        return false;
    }
};
 