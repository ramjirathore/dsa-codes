#include<iostream>
using namespace std;

// Problem -  Given a SORTED array, find all pairs that sum to K

// 1. normal approach where we select one element
// and search for the second el in remaining array O(n2)

// 2. Better would be to select one element and then
// do binary search for the second el

//3. Best would be two pointer approach - O(n)
// select first el and last el .. decrease/increase i j
// according to cases...till i j don't meet


//Doing third approach


int main() {
	int K;
	cin >> K;
	int a[] = {1, 3, 5, 7, 10, 11, 12, 13};

	int i, j;
	i = a[0];
	j = sizeof(a) / sizeof(int) - 1;

	while (i < j) {
		if (a[i] + a[j] < K) {
			i++;
		} else if (a[i] + a[j] > K) {
			j--;
		} else {
			cout << a[i] << " " << a[j] << endl;
			i++;
			j--;
		}
	}

}