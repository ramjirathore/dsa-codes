#include<iostream>
#include<algorithm>
using namespace std;


//Comparator function
bool compare(int a, int b) {
	return a > b;
}

void bubble_sort(int a[], int n, bool (&cmp)(int a, int b)) {
	// N-1 elements to the end
	for (int itr = 1; itr <= n - 1; itr++) {
		//Pairwise swapping in the unsorted array
		for (int j = 0; j <= n - itr - 1; j++) {
			if (cmp(a[j], a[j + 1])) {
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

	bubble_sort(arr, n, compare);

	// sort(arr, arr + n, compare);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}