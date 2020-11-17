#include<iostream>
using namespace std;

void insertion_sort(int arr[], int n) {
	for (int i = 1; i < n; i++) {
		int e = arr[i];

		// placing this element at its 'right' position in sorted part
		int j = i - 1;
		while (j >= 0 and arr[j] > e) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = e;
	}
}

int main() {
	int n;
	cin >> n;

	int arr[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	insertion_sort(arr, n);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}