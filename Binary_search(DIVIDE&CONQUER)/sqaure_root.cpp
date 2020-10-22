#include<iostream>
using namespace std;

// Note we are doing this for int/floor

float square_root(int n) {
	int s = 0;
	int e = n;

	float ans = -1;

	while (s <= e) {
		int mid = (s + e) / 2;

		if (mid * mid == n) {
			return mid;
		} else if (mid * mid < n) {
			ans = mid;
			s = mid + 1; // because then we search more bigger value
		} else {
			e = mid - 1;
		}
	}

	return ans;
}

int main() {
	int n;
	cin >> n;

	cout << square_root(n);
}