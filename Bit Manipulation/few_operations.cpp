#include<iostream>
#include<cstring>
using namespace std;

int isOdd(int n) {
	// if last bit is set then it is odd
	return n &  1;
}

int getBit(int n, int i) {
	// And with left shifted 1
	int mask = (1 << i);
	int set = (n & mask) > 0 ? 1 : 0;

	return set;
}

int setBit(int n, int i) {
	// OR with left shited 1
	int mask = (1 << i);
	return n | mask;
}

void clearBit(int &n, int i) {
	// And with negation of left shifted 1
	int mask = ~(1 << i);
	n = n & mask;
}

// update ith position bit with v (0 or 1)

void updateBit(int &n, int i, int v) {
	// step 1. Clear ith bit
	clearBit(n, i);

	// step 2. OR with v left shifted i places
	int mask = v << i;
	n = n | mask;
}


// NOTE: (~0) is -1   {since 2's complement of -1 is 11111111 which is same as ~0}
// 2's complement method: do 1's complement and 1 to it.

void clearLastiBits(int &n, int i) {
	// do AND with mask of left shifted 1's by i places
	int mask = -1 << i;
	n = n & mask;
}


// NOTE: answers can be different with 0 or 1 based indexing on bits
// so beware
int clearRangeItoJ(int n, int i, int j) {
	// This approach is considering 0 based indexing
	int ones = ~0;
	int a = ones << j + 1;
	int b = (1 << i) - 1;
	int mask = a | b;
	return n & mask;
}

int main() {
	int n, i;
	cin >> n >> i;

	// LEC - 1
	// string OorE = isOdd(n) ? "Odd" : "Even" ;

	// cout << OorE << endl;
	// cout << i << "th bit: " << getBit(n, i) << endl;
	// cout << "after setting " << i << "th bit: " << setBit(n, i) << endl;
	// clearBit(n, i);
	// cout << "after clearing " << i << "th bit: " << n << endl;


	// LEC - 2
	// int makeBitTo;
	// cin >> makeBitTo;

	// updateBit(n, i, makeBitTo);

	// cout << "after making " << i << "th bit to " << makeBitTo << " : " << n;


	// LEC - 3
	// clearLastiBits(n, i);
	// cout << "After clearing last " << i << " bits: " << n;

	int j;
	cin >> j;
	cout << "After clearing bits from range " << i << " to " << j << " : " << clearRangeItoJ(n, i, j);


}