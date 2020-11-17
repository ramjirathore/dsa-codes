#include<iostream>
using namespace std;

// segregate the array into three parts
// before l =>  all are 0
// between l and m => all are 1
// after h => all are 2

int main() {
	int n;
	cin >> n;
	int arr[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int low = 0, mid = 0;
	int high = n - 1;

	while (mid <= high) {
		if (arr[mid] == 0) {
			swap(arr[mid] , arr[low]);
			low++;
			mid++;
		} else if (arr[mid] == 1) {
			mid++;
		} else {
			swap(arr[mid], arr[high]);
			high--;
		}
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << endl;
	}
}