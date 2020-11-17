#include<iostream>
using namespace std;

// First Method: O(log(n))
int countSetBits(int n) {
	int count = 0;
	while (n > 0) {
		count += (n & 1) ; // Here (n&1) gives either 0 or 1 as output
		n = n >> 1;
	}
	return count;
}

// Second Method: Better approach O(no. of set bits) mostly
// rear worst case: O(log(n))
int countSetBitsFast(int n) { //  Brian Kernighan’s Algorithm
	int result = 0;
	while (n > 0) {
		n = n & (n - 1);
		result++;
	}
	return result;
}


int main() {
	int N;
	cin >> N;

	cout << countSetBits(N) << endl;
	cout << countSetBitsFast(N) << endl;

	//Method3: Built in method
	cout << __builtin_popcount(N);

}