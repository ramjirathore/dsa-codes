#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

// PROBLEM - Given an array of size n, find the majority element.
// The majority element is the element that appears more than ⌊ n/2 ⌋ times.
// Print -1 or majority element doesn't exist if it isn't there.


// Solutions-
// We will discuss four approaches (brute to optimal)

/* ---------------------------------------------------------------------------------------------------------*/

// Approach 1: Brute Force ------- TC: O(n*n) | SC: O(1)
// Calculate frequency for each unique element
// if it is more than n/2 than print it else print doesn't exist

void findMajorityViaBrute(vector<int> v, int size) {
	int maxCount = 0;
	int index = -1;

	for (int i = 0; i < size; i++) {
		int count = 0;
		for (int j = i; j < size; j++) {
			if (v[i] == v[j]) {
				count ++;
			}
		}

		if (count > maxCount) {
			index = i;
			maxCount = count;
		}
	}

	if (maxCount > size / 2) {
		cout << "Majority element: " << v[index];
	} else {
		cout << "Majority element doesn't exist";
	}
}

/* ---------------------------------------------------------------------------------------------------------*/

// Approach2: Using Sorting ------ TC: O(nlogn) | SC: O(1)
// Since the majority element freq > n/2
// This implies it occurs at mid in sorted array.
// So steps are: Sort the array. Find the mid element. Calculate its frequency
// And check if its > n/2

void findMajorityViaSorting(vector<int> v, int size) {
	sort(v.begin(), v.end());

	int assumedMajor = v[size / 2]; // mid element
	int count = 0;

	for (int i = 0; i < size; i++) {
		if (v[i] == assumedMajor) {
			count ++;
		}
	}

	if (count > size / 2) {
		cout << "Majority element: " << assumedMajor;
	} else {
		cout << "Majority element doesn't exist";
	}
}


/* -----------------------------------------------------------------------------------------------------------*/

// Approach 3: Using HashMap ------ TC: O(n) | SC: O(n)
// make a unordered map and put freq of each element
// check if any element's freq > n/2, print it
// else doesn't exist

void findMajorityViaHashMap(vector<int> v, int size) {
	unordered_map<int, int> mp;

	for (auto it : v) {
		mp[it]++;
	}

	bool flag = false;

	for (auto item : mp) {
		if (item.second > size / 2) {
			flag = true;
			cout << "Majority element: " << item.first;
			break;
		}
	}

	if (flag == false) {
		cout << "Majority element doesn't exist";
	}
}

/* -----------------------------------------------------------------------------------------------------------*/

// Approach 4 (OPTIMAL): Using MOORE's VOTING ALGORITHM ----- TC: O(n) | SC: 0(1)
// Two Steps:
// Step1: Find candidate : Traverse and assume first as major element along with count as 1
// check if next el is same as assumed one then increment count else decrement count
// and if count becomes zero then make the current as major and set count to 1

// Step2: Verify : calculate freq of the major and check if it is > n/2
// if yes => this is major else not

void findMajorityViaMoore(vector<int> v, int size) {
	int majorIndex = 0; // assuming major as first element
	int count = 1;

	// Find candidate ie v[majorIndex]
	for (int i = 1; i < size; i++) {
		if(v[i] == v[majorIndex]) {
			count++;
		} else {
			count --;
		}

		if(count == 0) {
			majorIndex = i;
			count = 1;
		}
	}

	int freq = 0;
	// verify it is major
	for(auto it: v) {
		if(v[majorIndex] == it) {
			freq++;
		}
	}

	if(freq > size/2) {
		cout<<"Majority element: "<<v[majorIndex];
	}
	else {
		cout << "Majority element doesn't exist";
	}

}


// Driver Code
int main() {
	vector<int> v;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	// findMajorityViaBrute(v, n);
	// findMajorityViaSorting(v, n);
	// findMajorityViaHashMap(v, n);
	findMajorityViaMoore(v, n);
}