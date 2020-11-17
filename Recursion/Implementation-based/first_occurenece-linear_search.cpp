#include<iostream>
using namespace std;

int linear_search(int arr[], int n, int key) {
	//base case
	if (n == 0) {
		return -1;
	}

	// recurence case(here doing two things)
	// --first checking for current index
	if (arr[0] == key) {
		return 0;
	}

	// --then making call to remaining part
	int i = linear_search(arr + 1, n - 1, key);
	if (i == -1) {
		return -1;
	}

	return i + 1;
}

int main() {
	int arr[] = {1, 2, 5, -2, 7, 11, 14, 7, 28};
	int n = sizeof(arr) / sizeof(int);

	int key = 7;

	cout << linear_search(arr, n, key);
}