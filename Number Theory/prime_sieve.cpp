#include<iostream>
#include<vector>
using namespace std;

#define ll long long


// Naive Approach - O(N)
// If called for N Numbers - O(N2)
bool checkPrime(int N) {

	if (N == 0 || N == 1)
		return false;

	if (N == 2)
		return true;

	// This can be improved
	for (int i = 2; i < N; i++) {
		if (N % i == 0) {
			return false;
		}
	}
	return true;
}

// Little better Approach than Naive - O(sqrtN)
// And if called for N number then - O(N*sqrtN)
bool checkPrimeOptimized(int N) {

	if (N == 0 || N == 1)
		return false;

	if (N == 2)
		return true;


	// 36 divisors - {2, 3, 6, 9, 12, 18}
	// it has pairs to make 36 basically
	// so a non prime will have a divisor in  < sqrt(N)
	// A prime won't => check till sqrtN

	for (int i = 2; i * i < N; i++) {
		if (N % i == 0) {
			return false;
		}
	}
	return true;
}


// MAIN APPROACH -->

// Sieve of erastothenes - Generate a array containing prime numbers
// for finding prime till N Numbers - O(N*loglogN)
void primeSieve(vector<int> &p, int n) {

	// first mark all odd no.s as prime
	for (int i = 3; i <= n; i += 2) {
		p[i] = 1;
	}


	// Sieve
	for (ll int i = 3; i <= n; i += 2) {
		// if current number is not marked => it is Prime
		if (p[i] == 1) {
			// set all multiples of i as non-Prime
			for (ll j = i * i; j <= n; j = j + i) {
				p[j] = 0;
			}
		}
	}

	// special case
	p[2] = 1;
	p[0] = p[0] = 0;
}



int main() {
	// Prime no.s upto N
	int N;
	cin >> N;

	vector<int> sieve(N, 0);

	primeSieve(sieve, N);

	for (int i = 0; i <= N; i++) {
		if (sieve[i]) {
			cout << i << " ";
		}
	}
	return 0;
}