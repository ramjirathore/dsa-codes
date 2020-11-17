#include<iostream>
using namespace std;

void bubble_sort(int a[], int n) {
	// N-1 elements to the end
	for (int itr = 1; itr <= n - 1; itr++) {
		//Pairwise swapping in the unsorted array
		for (int j = 0; j <= n - itr - 1; j++) {
			if (a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
			}
		}
	}
}

int main() {
	int n;
	cin >> n;

	int arr[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	bubble_sort(arr, n);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}