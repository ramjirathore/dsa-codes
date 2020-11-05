#include<iostream>
using namespace std;

// 1. Write a recursive function to perform Binary Search
// 2. Write a recursive function to perform power(a,n)
// 3. Write a recursive function to multiply two numbers without using * operator.



//Binary_search
int binary_search(int *arr, int k, int l, int h) {

	if (l > h) {
		return -1;
	}

	int mid = (l + h) / 2;
	if (arr[mid] == k) {
		return mid;
	} else if (arr[mid] > k) {
		return binary_search(arr, k, l, mid - 1);
	} else {
		return binary_search(arr, k, mid + 1, h);
	}
}

int main() {
	int arr[] = {1, 2, 5, 6, 10, 14, 25, 50};
	int n = sizeof(arr) / sizeof(int);

	int key = 10;
	cout << binary_search(arr, key, 0, n);

}