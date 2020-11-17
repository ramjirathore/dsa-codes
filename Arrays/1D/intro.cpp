#include<iostream>
#include<climits>
using namespace std;
int main() {

	// INITIALIZATION STUFF
	// int a[10] = {1, 2, 3};

	// int arrSize = sizeof(a)/sizeof(int);
	// cout << arrSize << endl;

	// for (int i=0; i<arrSize; i++) {
	// 	cout << a[i] << " " ;
	// }

	// LARGEST AND SMALLEST
	int a[10];

	cout << "Enter 10 values";
	for(int i=0; i<10; i++) {
		cin >> a[i];
	}

	int smallest = INT_MAX, largest = INT_MIN;
	for (int i=0; i<10; i++) {
		if(a[i] > largest) {
			largest = a[i];
		}
		if(a[i] < smallest) {
			smallest = a[i];
		}
	}

	cout <<"smallest is "<< smallest;
	cout << "largest is " << largest;

	return 0;
}