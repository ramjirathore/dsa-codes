#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	// for binarySearch the array must be sorted
	int arr[] = { 1, 10, 11, 11, 11, 45, 89};
	int n = sizeof(arr) / sizeof(int);

	int key;
	cin >> key;
	bool isThere = binary_search(arr, arr + n, key);
	if (isThere) {
		cout << key << " is Present" << endl;
	} else {
		cout << key << " is not Present" << endl;
	}

	// if we want index of key then

	// >= key
	auto lb = lower_bound(arr, arr + n, key);
	cout << "lower_bound: " << lb - arr << endl;

	// >key
	auto up = upper_bound(arr, arr + n, key);
	cout << "upper_bound: " << up - arr << endl;

	//frequency of element in sorted array
	cout << "frequency of " << key << " is " << (up - lb);
	return 0;
}