#include<iostream>
using namespace std; 

// PROBLEM - 0/1 Knapsack problem
// Solution - make subsets and then choose the one giving max profit
// Either include a object or exclude it

int profit(int *wts, int *prices, int n, int c) {
	// base case
	if(n==0 or c==0) {
		// if items get over or capcity is zero
		return 0;	
	}

	// rec case

	int ans = 0;
	int incl, excl;
	incl = excl = 0;

	//include the object
	if(wts[n-1] <= c) {
		incl = prices[n-1] + profit(wts, prices, n-1, c - wts[n-1]);
	}

	// exclude the object
	excl = profit(wts, prices, n-1, c);

	// select max of the subset
	ans = max(incl, excl);
	return ans;
}

int main() {
	int weights[] = {1, 2, 3, 5};
	int prices[] = {40, 20, 30, 100};

	int N = 4; // Total Items
	int C = 7; // Capcity of Bag

	int maxProfit = profit(weights, prices, N, C);
	cout<<maxProfit;

}
