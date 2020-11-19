#include<iostream>
using namespace std;

// Approach: Follow these three steps
// 1. Divide (into two arrays)
// 2. Sort (the two arrays by using comparison)
// 3. Merge (merge both the sub parts)

void merge(int *a, int s, int e) {
	int mid = (s + e) / 2;

	int i = s;
	int j = mid + 1;
	int k = s;

	int temp[100];

	// copy new sorted values into temp array
	while (i <= mid && j <= e) {
		if (a[i] < a[j]) {
			temp[k++] = a[i++];
		} else {
			temp[k++] = a[j++];
		}
	}

	// copy remaining values of first part if exists
	while (i <= mid) {
		temp[k++] = a[i++];
	}

	// copy remaining values of second part if exists
	while (j <= e) {
		temp[k++] = a[j++];
	}

	// copy temp array back to original array
	for (int m = s; m <= e; m++) {
		a[m] = temp[m];
	}

}

void mergeSort(int *a, int s, int e) {
	//base case
	if (s >= e) {
		return;
	}

	// rec case
	// step1: Divide
	int mid = (s + e) / 2;
	// step2: sort
	mergeSort(a, s, mid);
	mergeSort(a, mid + 1, e);

	// step3: merge
	merge(a, s, e);

}

int main() {
	int arr[] = {5, 4, 0 , 1, 8, -1, 6, 2};
	int n = sizeof(arr) / sizeof(int);

	mergeSort(arr, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}