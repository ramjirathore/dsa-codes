#include<iostream>
using namespace std;

int storeOccurences(int *arr, int  *occ, int i, int j, int key, int n) {
	// base case
	if (i == n) {
		return j;
	}

	if (arr[i] == key) {
		occ[j] = i;
		// increment j to accomodate currenct occurence
		return storeOccurences(arr, occ, i + 1, j + 1, key, n);
	}

	// j remains unchanged
	return storeOccurences(arr, occ, i + 1, j, key, n);

}


void allOccurence(int *arr, int i, int key, int n) {
	// base case
	if (i == n) {
		return;
	}

	if (arr[i] == key) {
		cout << i << " ";
	}

	allOccurence(arr, i + 1, key, n);
}

int main() {
	int arr[] = {1, 2, 4, 10, 3, 7, 5, 6, 7, 90, 7, 7, 10};
	int n = sizeof(arr) / sizeof(int);
	int key = 7;

	cout << "indexes of occurence of " << key << ": ";
	// allOccurence(arr, 0, key, n);

	int occurences[100];
	int occSize = storeOccurences(arr, occurences, 0, 0, key, n);


	for (int i = 0; i < occSize; i++) {
		cout << occurences[i] << " ";
	}


}