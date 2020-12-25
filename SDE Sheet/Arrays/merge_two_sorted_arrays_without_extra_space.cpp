// PROBLEM -

// Given two sorted arrays arr1[] and arr2[] of sizes N and Min non-decreasing order. 
// Merge them in sorted order without using any extra space.
// Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements. 

// Link - https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1#
// Solution - https://www.youtube.com/watch?v=hVl2b3bLzBw&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=4




// BRUTE FORCE - (Normal sorting approach) - O((n+m)log(n+m)) time and O(n+m) space

// Create a third array ..  {O(n+m) space}
// copy n and m elements to it .. {O(n+m) time}
// sort the array  .. { O((n+m)log(n+m)) time}
// place n elements to arr1 and m elements to arr2 ....{O(n+m) time}

// No need of code, very simple to implement :P







// BETTER -  (Insertion sort approach) - O(n*m) time and O(1) space

// Compare arr1 values with arr2 first value .. {O(n)}
// If greater then swap and then reorder the arr2 to place it at its correction position .. {O(m)}
// move forward in arr1

void merge(int arr1[], int arr2[], int n, int m) 
{ 
    
	for (int i = 0; i < n; i++) {
		if (arr1[i] > arr2[0]) {

			swap(arr1[i], arr2[0]);
			
			int j = 1, temp = arr2[0];
			
			while (j < m && arr2[j] < temp) {
				arr2[j - 1] = arr2[j];
				j++;
			}
			
			arr2[j-1] = temp;
		}
	}
} 