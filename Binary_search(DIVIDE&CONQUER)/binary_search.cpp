#include<iostream>
using namespace std;

int binary_search(int arr[], int n, int key) {
	int s = 0, mid;
	int e = n - 1;
	while (s <= e) {
		mid = (s + e) / 2;
		if (arr[mid] == key) {
			return mid;
		} else if (arr[mid] > key) {
			e = mid - 1;
		} else {
			s = mid + 1;
		}
	}
	return -1;
}

int main() {
	int arr[] = {1, 2, 3, 10, 20, 25, 56};
	int n = sizeof(arr) / sizeof(int);

	int key;
	cin >> key;

	int index = binary_search(arr, n, key);
	if (index != -1) {
		cout << "element found at " << index;
	} else {
		cout << "element doesn't exist";
	}
}