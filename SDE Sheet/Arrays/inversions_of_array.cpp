// Problem - 

// Given an array of integers. Find the Inversion Count in the array. 

// Inversion Count: For an array, inversion count indicates how far (or close) 
// the array is from being sorted. If array is already sorted then the inversion count is 0.
// If an array is sorted in the reverse order then the inversion count is the maximum. 
// Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

// Link - https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1#
// Solution - https://www.youtube.com/watch?v=kQ1mJlwW-c0 (or watch prateek narang's /tech dose sir explanation)



// BRUTE FORCE - O(n*n) time and O(1) space
// For each element traverse and count inversions



// Another shorter STL approach - O(n*n) time and O(1) space
// (Watch tech dose video for better understanding)
// Use multiset (since it can have repetitive values too)

// Insert a val 
// find its upperbound
// then find dist = size of multiset - this upperbound
// add this dist to inversion count

// After whole traversal the inversion count will be found




// OPTIMAL - (merge sort approach) - O(nlogn) time and O(n) space
// count inversions while merging
// crux - if left array index val is greater than right array index val 
// then all values to the right of the left array index value automatically gets included 


// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to find inversion count in the array

// arr[]: Input Array
// N : Size of the Array arr[]


long long int merge(long long *arr, long long s, long long e) {
    int i = s, k = s;
    int mid = (s+e)/2;
    int j = mid+1;
    
    long long *temp = new long long[10000000];
    long long count = 0;
    
    
    while(i<=mid && j<=e) {
        if(arr[i]<=arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];

            // all right values after the current included to inversion 
            count += mid - (i - 1);
        }
    }
    
    while(i<=mid) {
        temp[k++] = arr[i++];
    }
    
    
    while(j<=e) {
        temp[k++] = arr[j++];
    }
    
    for(int i=s; i<=e; i++) {
        arr[i] = temp[i]; 
    }
    
    delete []temp;
    return count;
}

long long int invCount(long long arr[], long long s, long long e) {
    // base case
    if(s>=e) {
        return 0;
    }
    
    //rec case
    int mid = (s+e)/2;
    long long x = invCount(arr, s, mid);
    long long y = invCount(arr, mid+1, e);
    
    long long z = merge(arr, s, e);
    
    return x+y+z;
}


long long int inversionCount(long long arr[], long long N)
{
    long long int ans = invCount(arr, 0, N-1);
    return ans;
}


// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        
        cout << inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends