#include<bits/stdc++.h>
using namespace std;

void removeDuplicates(char a[]) {
	int prev = 0;
	int l = strlen(a) - 1;

	for (int curr = 1; curr < l; curr++) {
		// we'll skip duplicates and copy unique character
		// whenever we find it
		if (a[prev] != a[curr]) {
			prev++;
			a[prev] = a[curr];
		}
	}
	// adding null character in the end
	a[l] = '\0';
}

int main() {
	char a[100];
	cin >> a;
	removeDuplicates(a);
	cout << a;
}