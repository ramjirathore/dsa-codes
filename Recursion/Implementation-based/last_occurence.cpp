#include<iostream>
using namespace std;

int last_occurence(int arr[], int n, int key) {
	//base case
	if (n == 0) {
		return -1;
	}

	// recurence case
	//first make call to remaining part
	int i = last_occurence(arr + 1, n - 1, key);

	if (i == -1) {
		//check for first el
		if (arr[0] == key) {
			return 0;
		} else {
			return -1;
		}
	}

	// otherwise if i returned by subproblem is not -1
	return i + 1;
}

int main() {
	int arr[] = {1, 2, 5, -2, 7, 11, 14, 7, 28};
	int n = sizeof(arr) / sizeof(int);

	int key = 7;

	cout << last_occurence(arr, n, key);
}