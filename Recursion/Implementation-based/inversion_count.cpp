#include<iostream>
using namespace std;

// Problem - Count total pairs in an array such that a[i] > a[j] & i < j
// Solution - We count using merge sort approach
// by breaking it into half parts

int merge(int *a, int s, int e) {
	int mid = (s + e) / 2;
	int i = s;
	int j = mid + 1;
	int k = s;

	int temp[1000];
	int count = 0;

	// sorting and copying into new array
	while (i <= mid && j <= e) {
		if (a[i] <= a[j]) {
			temp[k++] = a[i++];
		} else {
			temp[k++] = a[j++];
			// for ex 5 > 3 then all remaining elements > 5 are automatically included
			count += mid - (i - 1);
		}
	}

	// if one array has left elements store them then also
	while (i <= mid) {
		temp[k++] = a[i++];
	}
	while (j <= e) {
		temp[k++] = a[j++];
	}

	// copy back to original array
	for (int i = s; i <= e; i++) {
		a[i] = temp[i];
	}

	return count;
}


int inversionCount(int *a, int s, int e) {
	//base case
	if (s >= e) {
		return 0;
	}

	//rec case
	// Divide
	int mid = (s + e) / 2;
	int x = inversionCount(a, s, mid);
	int y = inversionCount(a, mid + 1, e);

	// merge (counting cross inversions ie from one part to other)
	int z = merge(a, s, e);

	// Return total count ()
	return x + y + z;
}

int main() {
	int arr[] = {1, 5, 2, 6, 3, 0};
	int n = sizeof(arr) / sizeof(int);

	int res = inversionCount(arr, 0, n - 1);
	cout << res;
}