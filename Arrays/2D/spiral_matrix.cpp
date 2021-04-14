// PROBLEM - Given a matrix of size R*C. Traverse the matrix in spiral form.

// Link - https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1
// SOLUTION - https://www.youtube.com/watch?v=1ZGJzvkcLsA&t=142s

// We basically take four pointers to mark the matrix
// (Assume it is mxn matrix)

//          top-> 1  2  3  4
//                5  6  7  8  
//                9  10 11 12
//          down->13 14 15 16
//               left     right

// Also one more pointer for direction .. dir
// since there are four possible directions here
// so it can have 0 1 2 3 values

// CODE -

class Solution
{   
public:     
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        int top = 0, down = r-1, left = 0, right = c-1;
        int dir = 0;
        // could be 0 1 2 3
        
        vector<int> ans; 
        while(top<=down && left<=right) {
            
            if(dir == 0) {
                for(int i=left; i<=right; i++) {
                    ans.push_back(matrix[top][i]);
                }
                top++;
            } else if(dir == 1) {
                for(int i=top; i<=down; i++) {
                    ans.push_back(matrix[i][right]);
                }
                right--;
            } else if(dir == 2) {
                for(int i=right; i>=left; i--) {
                    ans.push_back(matrix[down][i]);
                }
                down--;
            } else if(dir == 3) {
                for(int i=down; i>=top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
            
            dir= (dir+1)%4;
        }
        
        return ans;
    }
};