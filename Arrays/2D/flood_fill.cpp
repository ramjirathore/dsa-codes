// PROBLEM LINK -
// https://www.pepcoding.com/resources/online-java-foundation/recursion-backtracking/flood-fill-official/ojquestion#!

#include<iostream>
#include<string>
#include<vector>

using namespace std;

void floodfill(vector<vector<int>>maze, int row, int col, string psf, vector<vector<bool>>visited) {
    if(row < 0 || col<0 || row == maze.size() || col == maze[0].size() || maze[row][col]==1 || visited[row][col]==true) {
        return;
    }
    
    if(row == maze.size() -1 && col == maze[0].size() - 1) {
        cout<<psf<<endl;
        return;
    }
    
    visited[row][col] = true;
    
    floodfill(maze, row-1, col, psf+"t", visited);
    floodfill(maze, row, col-1, psf+"l", visited);
    floodfill(maze, row+1, col, psf+"d", visited);
    floodfill(maze, row, col+1, psf+"r", visited);
    
    visited[row][col] = false;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector < vector < int >> arr(n, vector < int > (m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    vector<vector<bool>> visited(n, vector<bool> (m));
    floodfill(arr, 0, 0, "", visited);
}