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


// Optimal - O(n*n) time and O(n*n) space
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


// Variations - 

//1. We are given row no. and col no. 
// and we have to find value in pascal triangle according to given row and column.

// Solution - O(n) time and O(1) space
// Basically we can find binomial its coeffcient 
// r-1
//    C     
//     c-1

// So basically for finding factorial - O(n) time 



//2. We are given row no. only and asked that row to return of pascal's triangle.

// Solution - O(n) and O(n) space
// for ex - given r = 5
// [4C0 4C1 4C2 4C3 4C4] will be ans row
// But we can use prev val everytime and just multiply 

// ie 4C1 = 4/1 
// then 4C2 can be calculated by 3*(4)/2*(1)
// similarly for others 
// thus achieving O(n) time


// Does not pass for higher values - cross check it 
vector<ll> nthRowOfPascalTriangle(int n) {
        vector<ll> row(n);
        row[0] = 1;
        
        ll res = 1;
        for(int i=1; i<n; i++) {
            res = res*(n-i)/i;
            row[i] =  res;
        }
        
        return row;
    }