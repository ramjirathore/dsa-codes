#include<bits/stdc++.h>
using namespace std;

void removeDuplicates(char a[]) {
	int l = strlen(a);
	// no need to check
	if (l == 0 or l == 1) {
		return;
	}

	int prev = 0;
	for (int curr = 1; curr < l; curr++) {
		// we'll skip duplicates and copy unique character
		// whenever we find it
		if (a[prev] != a[curr]) {
			prev++;
			a[prev] = a[curr];
		}
	}
	// adding null character in the end
	a[prev + 1] = '\0';
}

int main() {
	char a[100];
	cin >> a;
	removeDuplicates(a);
	cout << a;
}