// PROBLEM - 
// Given two binary max heaps as arrays, merge the given heaps, after merging the two arrays.
// The task is very simple to merge the two arrays firstly keep all the elements of first array 
// than elements second array, than apply the merge operation of heaps.

// LINK - https://practice.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1#

// Approach - O((n+m)log(n+m)) and O(1) space
// The problem is simple first add both arrays in merged array
// then build a heap using heapify function

void heapify(int *arr, int n, int i) {
    int left = 2*i+1;
    int right = 2*i+2;
    
    int minIdx = i;
    
    if(left < n && arr[minIdx] < arr[left]) {
        minIdx = left;
    } 
    
    if(right < n && arr[minIdx] < arr[right]) {
        minIdx = right;
    }
    
    if(minIdx!=i) {
        swap(arr[minIdx], arr[i]);
        heapify(arr, n, minIdx);
    }
}

void mergeHeaps(int merged[], int a[], int b[], int n, int m) {
   
    for(int i=0; i<n; i++) 
        merged[i] = a[i];
    
    for(int j=0; j<m; j++) 
        merged[n+j] = b[j];

    for(int i=(n+m)/2-1; i>=0; i--) {
        heapify(merged, n+m, i);
    }
    
}