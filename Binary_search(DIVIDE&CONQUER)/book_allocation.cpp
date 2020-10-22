#include<iostream>
#include<climits>
using namespace std;

bool isPossible(int arr[], int n, int m, int curr_min) {
	int studentUsed = 1;
	int pagesRead = 0;

	for (int i = 0; i < n; i++) {
		if (pagesRead + arr[i] > curr_min) {
			studentUsed++;
			pagesRead = arr[i];
			if (studentUsed > m) {
				return false;
			}
		} else {
			pagesRead += arr[i];
		}
	}
	return true;
}

int findPages(int arr[], int n, int m) {

	long long sum = 0;

	//students more than books
	if (n < m) {
		return -1;
	}

	for (int i = 0; i < n; i++) {
		sum += arr[i];
	}

	int s = arr[n - 1];
	int e = sum;
	int ans = INT_MAX;

	while (s <= e) {
		int mid = (s + e) / 2;
		if (isPossible(arr, n, m, mid)) {
			ans = mid;
			e = mid - 1;
		} else {
			// it is not possible
			// to divide at x pages so we have to increase the no. of pages
			s = mid + 1;
		}
	}

	return ans;
}

int main()
{
	int T;
	cin >> T;

	while (T--) {
		int n, m;
		cin >> n >> m;

		int arr[1000];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		cout << findPages(arr, n, m);
	}

	return 0;
}