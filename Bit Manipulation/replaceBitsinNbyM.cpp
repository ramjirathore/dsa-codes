#include<iostream>
using namespace std;

// Replace Bits in N by M

// You are given two 32-bit numbers, N and M, and two bit positon, i and  j.
// Write a method to set all bits between i and j in N equal
// to M (e.g., M becomes a substring of N located at i and starting at j).

// EXAMPLE:
// Input: N = 10000000000,(binary form) --> 2048
// M = 10101 --> 21, i =2, j = 6
// Output: N = 10001010100 --> 2132

void clearBitsItoJ(int &n, int i, int j) {
	int a = (1 << i) - 1;
	int b = (-1 << j + 1);
	int mask = a | b;
	n = n & mask;
}


int main() {
	int N, M, i, j;
	cin >> N >> M >> i >> j;
	clearBitsItoJ(N, i, j);

	int newMask = M << i;
	int result = N | newMask;
	cout << result;

}