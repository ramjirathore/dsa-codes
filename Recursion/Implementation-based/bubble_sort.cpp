#include<iostream>
using namespace std;

void bubble_sort(int *a, int n) {
	// base case
	if (n == 1) {
		return;
	}

	// rec case
	// pop/bubble the largest element to end
	for (int j = 0; j < n - 1; j++) {
		if (a[j] > a[j + 1]) {
			swap(a[j], a[j + 1]);
		}
	}

	// repeat for next pass
	bubble_sort(a, n - 1);
}


// purely recursive-> (j handles inside loop ie popping out and n handles passes loop)
void bubble_sort_recursive(int *a, int j, int n) {
	// base case
	if (n == 1) {
		return;
	}
	if (j == n - 1) { // ie last element reached
		// single pass of current array has been done
		return bubble_sort_recursive(a, 0, n - 1);
	}

	// rec case
	if (a[j] > a[j + 1]) {
		swap(a[j], a[j + 1]);
	}

	// check for next value in same pass
	bubble_sort_recursive(a, j + 1, n);
	return;
}

int main() {
	int arr[] = {5, 4, 1, 3, 2};
	int n = sizeof(arr) / sizeof(int);

	// bubble_sort(arr, n);
	bubble_sort_recursive(arr, 0, n);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}