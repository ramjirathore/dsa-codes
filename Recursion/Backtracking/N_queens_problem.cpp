#include<iostream>
using namespace std;

// PROBLEM - Place N queens on NXN board such that all queens are safe.
// SOLUTION - Put a queen check it is safe to put and repeat for the next remaining rows


bool isSafe(int board[][10], int i, int j, int n) {
	

	// check for column (-- ie if there's no other queen in current column)
	for(int row=0; row<i; row++) {
		if(board[row][j] == 1) {
			return false;
		}
	}

	int x = i;
	int y = j;

	// check in Left diagonal
	while(x>=0 && y>=0) {
		if(board[x][y] == 1) {
			return false;
		}
		x--;
		y--;
	}

	// resetting to current position
	x = i;
	y = j;

	// check in Right diagonal 
	while(x>=0 && y<n) {
		if(board[x][y] == 1) {
			return false;
		}
		x--;
		y++;
	}

	// We reach here if there is no queen in col and diagonals => Safe to put
	return true;
}


bool solveNQueen(int board[][10], int i, int n) {
	// base case
	if(i==n) {
		// You have successfully placed queens in n rows (0.....n-1)
		// So Print the board 
		for(int row=0; row<n; row++) {
			for(int col=0; col<n; col++) {
				if(board[row][col] == 1) {
					cout<<"Q ";
				} else {
					cout<<"_ ";
				}
			}
			cout<<endl;
		}
		cout<<endl<<endl;
		
		// #### ->

		// For printing ONLY ONE SOLUTION - tell this is the solution and finish
		// return true; 
		
		// For printing ALL SOLUTIONS -- we tell the current solution is wrong and thus program tries again
		return false;
	}

	
	// Recursive Case

	// Try to place the queen in current row and call on remaining part
	// Which will be solve by recursion
	for(int j=0; j<n; j++) {
	
		// Check if i, j th position is safe to place the queen
		if(isSafe(board, i, j, n)) {
			
			// Place the Queen - Assuming i, j is the right position
			board[i][j] = 1;

			// check for next queen
			bool nextQueenRakhPaye = solveNQueen(board, i+1, n);
			if(nextQueenRakhPaye) {
				return true;
			}

			// Means i, j is not the right position -- Assumption is wrong
			board[i][j] = 0; // Thus, Backtrack
		}
	}

	// You have tried all positions in current row but couldn't place a queen
	return false;
}


// Driver Code
int main() {
	int board[10][10] = {0};
	int N;
	cin>>N;

	solveNQueen(board, 0 , N);

	return 0;
}