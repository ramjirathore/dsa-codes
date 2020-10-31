#include<iostream>
using namespace std;

void dec(int n) {
	// Base case
	if (n == 0) {
		return;
	}

	// ** The function call is AFTER so this is top to bottom
	cout << n << " ";
	dec(n - 1);
}


void inc(int n) {
	// Base case
	if (n == 0) {
		return;
	}

	// ** The function call is BEFORE so this is bottom to top.
	inc(n - 1);
	cout << n << " ";

}

int main() {
	int n;
	cin >> n;

	cout << "Decreasing order: ";
	dec(n);
	cout << endl;
	cout << "Increasing order: ";
	inc(n);

	return 0;
}