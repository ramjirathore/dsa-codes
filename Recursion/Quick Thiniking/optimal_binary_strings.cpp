#include<iostream>
using namespace std;

// #COUNT BINARY STRINGS
// Count Binary Strings of Length of N, which have No consecutive ones?

// Solution - if we consider last digit-
// As 0 then we can select to select for n-1
// As 1 then second last can't be 1 so we can select for n-2

int totalStrings(int n) {
	// base case
	if (n == 0) {
		return 1;
	}
	if (n == 1) {
		return 2;
	}

	// rec case
	return totalStrings(n - 1) + totalStrings(n - 2);
}

int main() {
	int n;
	cin >> n;

	int ans = totalStrings(n);
	cout << ans;

}