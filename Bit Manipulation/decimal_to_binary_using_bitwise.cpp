#include<iostream>
using namespace std;

int decimalToBinary(int n) {
	int ans, p = 1;
	while (n > 0) {
		ans += (n & 1) * p;
		p = p * 10; // reverse we get.. so had to add powers of base 10 integer
		n = n >> 1;
	}
	return ans;
}

int main() {
	int n;
	cin >> n;

	int bin = decimalToBinary(n);
	cout << bin;
}