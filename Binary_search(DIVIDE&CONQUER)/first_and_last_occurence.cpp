#include<iostream>
using namespace std;

int first_occurenece(int arr[], int n , int key) {
	int s = 0, mid;
	int e = n - 1;

	int ans = -1;

	while (s <= e) {
		mid = (s + e) / 2;
		if (arr[mid] == key) {
			ans = mid;
			e = mid - 1; // move to left and keep checking for key
		} else if (arr[mid] > key) {
			e = mid - 1;
		} else {
			s = mid + 1;
		}
	}
	return ans;
}

int last_occurenece(int arr[], int n , int key) {
	int s = 0, mid;
	int e = n - 1;

	int ans = -1;

	while (s <= e) {
		mid = (s + e) / 2;
		if (arr[mid] == key) {
			ans = mid;
			s = mid + 1; // move to right and keep checking for key
		} else if (arr[mid] > key) {
			e = mid - 1;
		} else {
			s = mid + 1;
		}
	}
	return ans;
}

int main() {
	int arr[] = {1, 2, 3, 4, 7, 7, 7, 8, 8, 9, 10};
	int n = sizeof(arr) / sizeof(int);

	int key;
	cin >> key;

	int lb = first_occurenece(arr, n, key);
	int ub = last_occurenece(arr, n, key);

	cout << lb << " " << ub;

}