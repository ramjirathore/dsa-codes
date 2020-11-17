#include<iostream>
#include<climits>
using namespace std;

int isPossible(int arr[], int P, int C, int curr_min) {
	int prataCount = 0;
	int timeToMakePrata, totalPrata = 0;

	for (int i = 0; i < C; i++) {
		timeToMakePrata = arr[i];
		while (timeToMakePrata + prataCount * arr[i] < curr_min) {

			timeToMakePrata += prataCount * arr[i];
			cout << timeToMakePrata << " ";

			prataCount ++;
		}
		totalPrata += prataCount;
		prataCount = 0;
		cout << endl << endl;
	}

	if (totalPrata >= P)
		return true;
	else
		return false;
}

int timeToCook(int arr[], int P , int C) {
	int max_time = 0;

	int s = 0;
	int e = 100;
	int ans = INT_MAX;

	while (s <= e) {
		int mid = (s + e) / 2;
		if (isPossible(arr, P, C, mid)) {
			ans = mid;
			e = mid - 1;
		}
		else {
			s = mid + 1;
		}
	}
	return ans;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int P, C;
		cin >> P >> C;
		int arr[100];

		for (int i = 0; i < C; i++) {
			cin >> arr[i];
		}
		// cout << "hello";
		timeToCook(arr, P, C) ;
	}

}