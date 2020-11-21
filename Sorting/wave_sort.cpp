#include<iostream>
using namespace std;

// Problem: Sort the given array such that is form wave is B S B S B S
// where B is Big Number and S is Small Number


// TC: O(n)
// Solution -
// One way to do is sort the array and then swap alternate elements (O(nlogn + n) => O(nlogn))
// Other way is to check if a element at jump of 2 is greater than previous and next element
// If Not then swap it with respective one , O(n)

void waveSort(int *a, int n) {
	for (int i = 0; i < n; i+=2) { // jump of 2
		// Previous element check
		if (i != 0 and a[i] < a[i - 1]) {
			swap(a[i], a[i - 1]);
		}

		//Next element check
		if (i != n - 1 and a[i] < a[i + 1]) {
			swap(a[i], a[i + 1]);
		}
	}
}

int main() {
	int a[] = {1, 3, 4, 2, 7, 8, 9};
	int n = sizeof(a) / sizeof(int);


	waveSort(a, n);

	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}