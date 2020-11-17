#include<iostream>
using namespace std;


// PROBLEM- RAT IN A MAZE
// Given a MXN matrix, with some cells as blocked you have to-
// 1. Find path from src to dest
// 2. Count the no. of paths from src to dest 
// 3. Print all possible paths (--This one we are solving--)

// Allowed moves- forward | downward (can't move out maze)

bool ratInMaze(char maze[10][10], int soln[][10], int i, int j, int m, int n) {
	// base case
	if(i==m && j==n) {
		soln[m][n] = 1;
		// Print the solutions
		for(int i=0; i<=m; i++) {
			for(int j=0; j<=n; j++) {
				cout<<soln[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;

		return true;
	}

	// can't move outside sunce rat should be inside grid
	if(i>m || j>n) {
		return false;
	}

	if(maze[i][j] == 'X') {
		return false;
	}

	//rec case

	// assume the solution exits through current cell
	soln[i][j] = 1;

	bool rightSuccess = ratInMaze(maze, soln, i, j+1, m, n);
	bool downSuccess = ratInMaze(maze, soln, i+1, j, m, n);

	// backtracking
	soln[i][j] = 0;


	// if any true then move ahead
	if(rightSuccess || downSuccess) {
		return true;
	}
	// else not
	return false;

}

int main() {

	char maze[10][10] = {
		"0000",
		"00X0",
		"000X",
		"0X00"
	};

	int soln[10][10] = {0};

	int m = 4;
	int n = 4;

	bool ans = ratInMaze(maze, soln, 0, 0, m-1, n-1);
	if(ans == false) {
		cout<<"Path doesn't exist";
	}

	return 0;

}