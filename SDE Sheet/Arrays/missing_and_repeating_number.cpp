// PROBLEM - 
// Given an unsorted array Arr of size N of positive integers. 
// One number 'A' from set {1, 2, …N} is missing and one number 'B' occurs twice in array. 
// Find these two numbers.

// LINK - https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/
// SOLUTION - https://www.youtube.com/watch?v=5nMGY4VUoRY&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=3

// Brute force - Sort and then find => O(nlogn+n) time and O(1) space

// Hashmap or frequency array - O(n) time and O(n) space


// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends

//Sort and then find- O(nlogn +n) time and O(1) space

class Solution{
public:
    int *findTwoElement(int *arr, int n) {
       vector<int, int> v(n, 0);
    //   for(int i=0; i<n; i++) {
    //       v[arr[i]] += 1;
    //   }
       
       int *x = new int[0];
       
    //   for(int i=0; i<n; i++) {
    //       if(v[i] == 2) {
    //           x[0] = arr[i];
    //       }
           
    //       if(v[i] == 0) {
    //           x[1] = i + 1;
    //       }
    //   }
       return x;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends