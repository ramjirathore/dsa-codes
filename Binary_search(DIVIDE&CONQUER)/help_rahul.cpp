#include<iostream>
using namespace std;


// In this problem Hint: make a graph
// Then you'll see there could be possibly two midpoints

int find_key(int arr[], int n, int key) {
	int s = 0;
	int e = n - 1;

	while (s <= e) {
		int mid = (s + e) / 2;
		if (arr[mid] == key) {
			return mid;
		} else if (arr[mid] > key) {
			if (arr[s] <= arr[mid] && key >= arr[s]) {
				e = mid - 1;
			} else {
				s = mid + 1;
			}
		} else {
			if (arr[e] >= arr[mid] && key <= arr[e]) {
				s = mid + 1;
			} else {
				e = mid - 1;
			}
		}
	}
	return -1;
}

int main() {
	int arr[100];
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int key;
	cin >> key;

	cout << find_key(arr, n, key);
}