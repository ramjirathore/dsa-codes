#include<iostream>
using namespace std;


int partition(int *a, int s, int e) {
	int pivot = a[e];

	// Inplace( can't take extra array)
	int i = s - 1;
	int j = s;

	while (j <= e - 1) {
		if (a[j] <= pivot) {
			// merge the smaller element in smaller region
			i = i + 1;
			swap(a[i], a[j]);
		}

		// expand the larger region
		j = j + 1;
	}

	// place the pivot in the current index/position
	swap(a[i + 1], a[e]);
	return i + 1;
}

void quickSort(int *a, int s, int e) {
	//base case
	if (s >= e) {
		return;
	}

	// rec case

	// (place the pivot at correct place)
	int p = partition(a, s, e); // returning index of correctly placed pivot
	// left part
	quickSort(a, s, p - 1);
	// right part
	quickSort(a, p + 1, e);
}

int main()
{
	int arr[] = {2, 7, 8, 6, 1, 5, 4};
	int n = sizeof(arr) / sizeof(int);

	quickSort(arr, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}