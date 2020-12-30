// PROBLEM - (Leetcode)

// Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row.

// Two variations ->
// Link (Leetcode) - https://leetcode.com/problems/search-a-2d-matrix/
// Link (GFG) - https://practice.geeksforgeeks.org/problems/search-in-a-matrix17201720/1

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


// BETTER (though OPTIMAL for GFG) - O(n+m)) time and O(1) space
// Note - Problem states every row and every column is sorted
// (But that doesn't mean its always linearly sorted if put in one line)

// Start from the last column of first row
// check if target < current val 
// if yes move back one step in same row
// else move down one step in same column

// if any time you got out of matrix => not present

class Solution{
public:	
	int matSearch (vector <vector <int>> &mat, int N, int M, int X)
	{
        int i = 0;
        int j = M-1;
        
        while(i<N && j>=0) {
            if(mat[i][j] == X) {
                return 1;
            } else if (mat[i][j] > X) {
                j--;
            } else {
                i++;
            }
        }
        
        return 0;
	}
};



// OPTIMAL - O(log(n*m)) time and O(1) space
// 2nd point tells that the whole matrix if put in a single array
// Then it will be sorted
// we will exhaust this by using binary search
// But without any extra space
// #imp - we calc row and col of mid using mid/m and mid%m

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(!matrix.size()) return false;
        
        int n = matrix.size();
        int m = matrix[0].size();
        
       int low = 0;
       int high = n*m - 1;
        
        while(low<=high) {
            int mid = low + (high - low)/2;
            
            if(matrix[mid/m][mid%m] == target) {
                return true;
            } else if(matrix[mid/m][mid%m] < target) {
                low = mid + 1; 
            } else {
                high = mid - 1;
            }
        }
        
        return false;
    }
};