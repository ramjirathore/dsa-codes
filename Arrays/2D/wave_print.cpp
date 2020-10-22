#include<iostream>
using namespace std;

int main() {
	int arr[10][10], val = 0;

	for (int row = 0; row < 3; row++ ) {
		for (int col = 0; col < 4; col++) {
			val++;
			arr[row][col] = val;
		}
	}


	for (int col = 0; col < 4; col++) {
		if (col % 2 == 0) {
			//even col-top down
			for (int row = 0; row < 3; row++) {
				cout << arr[row][col] << " ";
			}
		} else {
			//odd col-bottom up
			for (int row = 2; row >= 0; row--) {
				cout << arr[row][col] << " ";
			}
		}
		cout << "-- ";
	}
}