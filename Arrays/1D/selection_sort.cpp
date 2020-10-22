#include<iostream>
using namespace std; 


// Selection sort - We find min and then replace it first element 
//. .. repeat the same for remaining array


void selection_sort(int a[], int n) {

	// Will do it n-1 times since last element gets placed itself
	for(int i=0; i<n-1; i++) {
		int min_index = i;
		for(int j=i; j<n; j++) {
			if(a[j] < a[min_index]) {
				min_index = j;
			}
		}
		// Finally after the loop we swap 
		swap(a[i], a[min_index]);
	}
}

int main() {
	int arr[10], key;

	for (int i=0; i<10; i++) {
		cin>>arr[i];
	}

	selection_sort(arr, 10);

	for(int i=0; i<10; i++) {
		cout<<arr[i] << " ";
	}
}