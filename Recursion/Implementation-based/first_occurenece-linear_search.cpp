#include<iostream>
using namespace std;

int linear_search(int arr[], int n, int key) {
	//base case
	if (n == 0) {
		return -1;
	}

	// recurence case
	if (arr[0] == key) {
		return 0;
	}

	int i = linear_search(arr + 1, n - 1, key);
	if (i == -1) {
		return -1;
	}

	return i + 1;
}

int main() {
	int arr[] = {1, 2, 5, -2, 11, 14, 28};
	int n = sizeof(arr) / sizeof(int);

	int key;
	cin >> key;

	cout << linear_search(arr, n, key);
}