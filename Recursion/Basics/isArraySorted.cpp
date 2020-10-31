#include<iostream>
using namespace std;

bool isArraySorted(int *a, int n) {
	// Base case
	if (n == 0 or n == 1) {
		return true;
	}

	// recursive case
	if (a[0] < a[1] and isArraySorted(a + 1, n - 1)) {
		return true;
	}

	return false;
}

int main() {
	int arr[] = {1, 2, 3, 4, 5};
	int n = sizeof(arr) / sizeof(int);

	// 1 if sorted else 0
	cout << isArraySorted(arr, n);
}