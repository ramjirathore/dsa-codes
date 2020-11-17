#include<iostream>
#include<algorithm>
using namespace std;

bool compare(int a, int b) {
	return a > b;
}

int main() {
	int arr[] = { 6, 5, 7, 1, 0, 8, 7};
	int n = sizeof(arr) / sizeof(int);


	sort(arr, arr + n, compare);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

}