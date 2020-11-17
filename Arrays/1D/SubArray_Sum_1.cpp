#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n, maxSum = 0;
	int left = -1, right = -1;

	cin >> n;

	int arr[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}


	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {

			int currSum = 0;

			// calculating sum for all sub arrays
			for (int k = i; k <= j; k++) {
				currSum += arr[k];
			}

			// comparing current sum with max array sum
			if (currSum > maxSum) {
				maxSum = currSum;
				left = i;
				right = j;
			}
		}
	}

	// printing that subarray whose sum is max
	for (int p = left; p <= right; p++) {
		cout << arr[p] << " ";
	}

	cout << "\n" << "maxSum is " << maxSum;

}