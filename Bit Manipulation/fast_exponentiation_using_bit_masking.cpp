#include<iostream>
using namespace std;


// Problem - Calcluate exponent (in optimized way)
// Solution: O(log n) (since n has logn set bits)

int power_optimized(int a, int n) {
	// Convert n into binary form
	// Multiply.. if bit is set

	int ans = 1; // since any number to power something >=1
	while (n > 0) {
		int last_bit = n & 1;
		if (last_bit) {
			ans = ans * a;
		}
		a = a * a; // Square up
		n >>= 1; // shift one bit to right
	}

	return ans;
}

int main() {
	int a, n;
	cin >> a >> n;

	cout << "result: " << power_optimized(a, n);

}