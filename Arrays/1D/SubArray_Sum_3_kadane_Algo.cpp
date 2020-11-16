#include<iostream>
using namespace std;

int main() {
	int n;

	cin >> n;
	int arr[n];

	int cs = 0;
	int ms = 0;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		cs += arr[i];
		ms = max(cs, ms); // This must be first otherwise it will give 0 for only negative values
		if (cs < 0) {
			cs = 0;
		}
	}

	cout << "max Subarray sum is" << ms;
}
