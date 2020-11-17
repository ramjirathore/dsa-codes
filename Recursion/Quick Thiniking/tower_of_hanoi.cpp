#include<iostream>
using namespace std;

// Problem - Classical Problem of tower of hanoi
// You can move 1 disk at a time
// You cannot put larger disk over small one

// Solution -
// 1. Put n-1 disks on aux/helper tower
// 2. put last disk on destination
// 3. then put n-1 disks above the last one.

void move(int n, char src, char helper, char dest) {
	//base case
	if (n == 0) {
		return;
	}

	// rec case
	// move n-1 to helper
	move(n - 1, src, dest, helper);
	// shift last disk to destination
	cout << "Shift " << n << " from " << src << " to " << dest << endl;
	// move n-1 disks to destination
	move(n - 1, helper, src, dest);
}

int main() {
	int n; //number of disks
	cin >> n;

	// A is source, B is auxilary/helper, C is destination
	move(n, 'A', 'B', 'C');

	return 0;
}