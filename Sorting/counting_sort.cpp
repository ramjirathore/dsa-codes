#include<iostream>
#include<vector>
using namespace std;

// Note - Counting Sort is best for small range of numbers (>0) 

// TC: O(n+range)
// range = b - a 
// b is largest , a is smallest

void countingSort(int *a, int size) {
	// find largest - assuming all numbers are positive
	int largest = -1;
	for(int i=0; i<size; i++) {
		if(a[i] > largest) {
			largest = a[i];
		}
	}

	// create freq array
	int *freq = new int[largest+1]{0};
	for(int i=0; i<size; i++) {
		freq[a[i]]++;
	}

	//put the elements back into array a by reading freq array
	int j =0;
	for(int i=0; i<=largest; i++) {
		while(freq[i] > 0) {
			a[j] = i;
			freq[i]--;
			j++;
		}
	}

}

int main() {
	int arr[] = {88, 97, 10, 12, 1, 5, 6, 12, 5, 8};
	int n = sizeof(arr)/sizeof(int);

	countingSort(arr, n);

	for(int i=0; i<n; i++) {
		cout<<arr[i] <<" ";
	}

}