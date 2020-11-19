#include<iostream>
#include<cmath>
using namespace std;

// PROBLEM - Given a N x N soduko, N is a perfect square, write an algorithm which finds a possible solution

// SOLUTION -
// Fill cell by cell and call recursivley for remiaining part
// if we could place the value in current cell then move forward
// else come back retry with another number

// Three conditions we have to check everytime (for each non-filled cell)->
// It must not be in column already
// must not be in row already
// must not be in the subgrid (in which the number belongs)

bool canBePlaced(int mat[][9], int i, int j, int n, int num) {
	// check in row and column (if the number doesn't exist already)
	for (int x = 0; x < n; x++) {
		if (mat[i][x] == num || mat[x][j] == num) {
			return false;
		}
	}

	// check in subgrid
	int rn = sqrt(n); // root n

	// we need starting point of subgrid to do that
	int sx = (i / rn) * rn;
	int sy = (j / rn) * rn;

	for(int i=sx; i<sx+rn; i++) {
		for(int j=sy; j<sy+rn; j++) {
			if(mat[i][j] == num) {
				return false;
			}
		}
	}

	// Number doesn't exist in row, column or subgrid
	return true;
}


int solveSudoku(int mat[][9], int i, int j, int n) {
	// base case
	if (i == n) {
		// We have completed the suduko
		// So Print the matrix

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout<<mat[i][j] << " | ";
			}
			cout <<endl;
		}

		return true;
	}

	// Current row finished or case row end
	if (j == n) {
		return solveSudoku(mat, i + 1, 0, n);
	}

	// skip the pre-filled cells
	if (mat[i][j] != 0) {
		return solveSudoku(mat, i, j + 1, n);
	}

	// Recursive case
	// Fill the current cell with possible solutions
	for (int number = 1; number <= n; number++) {
		if (canBePlaced(mat, i, j, n, number)) {
			// Assume it can be placed
			mat[i][j] = number;

			bool couldWeSolve = solveSudoku(mat, i, j + 1, n);
			if (couldWeSolve) {
				return true;
			}
		}
	}

	// Reaching here means - we couldn't place any number
	mat[i][j] = 0; // so, Backtrack here

	return false;

}


int main() {
	int sodukuMatrix[9][9] = {
		{5, 3, 0, 0, 7, 0, 0, 0, 0},
		{6, 0, 0, 1, 9, 5, 0, 0, 0},
		{0, 9, 8, 0, 0, 0, 0, 6, 0},
		{8, 0, 0, 0, 6, 0, 0, 0, 3},
		{4, 0, 0, 8, 0, 3, 0, 0, 1},
		{7, 0, 0, 0, 2, 0, 0, 0, 6},
		{0, 6, 0, 0, 0, 0, 2, 8, 0},
		{0, 0, 0, 4, 1, 9, 0, 0, 5},
		{0, 0, 0, 0, 8, 0, 0, 7, 9}
	};

	solveSudoku(sodukuMatrix, 0, 0, 9); // N is 9 here

	return 0;
}