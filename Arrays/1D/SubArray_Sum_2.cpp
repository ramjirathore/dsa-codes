#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n, maxSum = 0, currSum = 0;
	int left = -1, right = -1;

	cin >> n;

	int arr[n], cumSum[n];

	cin >> arr[0];
	cumSum[0] = arr[0];

	for (int i = 1; i < n; i++) {
		cin >> arr[i];
		cumSum[i] = cumSum[i - 1] + arr[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {

			currSum = 0;
			currSum = cumSum[j] - cumSum[i - 1];

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