#include<iostream>
using namespace std;

// PROBLEM - Given an array of 0s,1s and 2s. Sort them in linear time.

// TC: O(n)

// SOLUTION- We create three regions of 0s, 1s and 2s.
// |0 0 0 0 || 1 1 1 1 || 2 1 0 1 2 0 || 2 2 2 2 |
//  |                     |         |
// low                   mid       high

void dnf_sort(int *a, int n) {

	int low, mid;
	low = mid = 0;
	int high = n - 1;

	while (mid <= high) {
		if (a[mid] == 0) {
			swap(a[low], a[mid]);
			low++;
			mid++;
		} else if (a[mid] == 1) {
			mid++;
		} else if (a[mid] == 2) {
			swap(a[mid], a[high]);
			high--;
		}
	}
}

int main() {
	int arr[] = {2, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 2, 0};
	int n = sizeof(arr) / sizeof(int);

	dnf_sort(arr, n);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}