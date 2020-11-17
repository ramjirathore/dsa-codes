#include<iostream>
using namespace std;

// PROBLEM - You are given N steps to climb
// You can climb either 1, 2 ,3 ..K at one time.
// Count total ways you can climb N steps.

int f(int n , int k) {
	//base case
	if (n == 0) {
		// if no step that is also a way
		return 1;
	}

	if (n < 0) {
		return 0;
	}


	// rec case
	int ans = 0;
	for (int i = 1; i <= k; i++) {
		ans += f(n - i, k);
	}

	return ans;
}

int main() {
	int n, k;
	cin >> n >> k;

	int totalWays = f(n, k);
	cout << totalWays;
}