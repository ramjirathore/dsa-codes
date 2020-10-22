#include<bits/stdc++.h>
using namespace std;

// Find out number which is not repeated


int main() {
	int n;
	cin >> n;

	int x;
	int ans = 0;

	// Best approach is to use XOR
	// Reason: a^b^a = b
	// also a^b^c^a^c = b

	// also helped not to use any extra storage
	// we did it in CONSTANT SPACE

	for (int i = 0; i < n; i++) {
		cin >> x;
		ans = ans ^ x;;
	}

	cout << ans;
}