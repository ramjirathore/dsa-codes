#include<iostream>
using namespace std;

// O(N)
int power(int a, int n) {
	// base case
	if (n == 0) {
		return 1;
	}

	return a * power(a, n - 1);
}


// efficient log(N) method-
// case1: if a odd -> use a*(a^n/2)^2
// case2: if a even -> use (a^n/2)^2
int fast_power(int a, int n) {
	// base case
	if (n == 0) {
		return 1;
	}

	// calculate smaller exponent
	int smaller_expo = fast_power(a, n / 2); // or use n>>1
	smaller_expo *= smaller_expo;

	// if odd
	if (n & 1) {
		return a * smaller_expo;
	}

	// else for even
	return smaller_expo;
}
int main() {
	int a, n;
	cin >> a >> n;

	cout << power(a, n) << endl;

	cout << fast_power(a, n);
}