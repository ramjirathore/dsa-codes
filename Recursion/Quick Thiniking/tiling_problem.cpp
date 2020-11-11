#include<iostream>
using namespace std;

// PROBLEM: #PLACE THE TILES
// Given a Wall of 4 X N size, and tiles of size(1,4) and (4,1).
// In how many ways you can build the wall?

int waysToBuild(int n) {
	// base case
	if (n <= 3) {
		// since only one way is possible ie to place (4,1)
		return 1;
	}

	// rec case
	// if placed one (4,1) then you can place n-1 similarly
	// or if placed (1,4) then you can place n-4 similarly

	// combination is possible
	return waysToBuild(n - 1) + waysToBuild(n - 4);
}

int main() {
	int N;
	cin >> N;

	int ans = waysToBuild(N);
	cout << ans;

}