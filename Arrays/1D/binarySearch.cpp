#include<iostream>
using namespace std; 

int binary_search(int *arr, int n, int key) {

	int s = 0;
	int e = n-1;
	int mid; 

	while(s <= e) {
		mid = (s+e) / 2;

		if(arr[mid] == key) {
			return mid;
		}else if(arr[mid] > key ) {
			e = mid - 1;
		} else {
			s = mid + 1;
		}
	} 

	return -1;
}

int main() {
	int arr[10], key;

	for (int i=0; i<10; i++) {
		cin>>arr[i];
	}

	cout<<"Enter the key";
	cin>>key;

	cout<<"index : "<<binary_search(arr, 10, key);
}