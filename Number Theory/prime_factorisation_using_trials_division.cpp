#include<iostream>
#include<vector>
using namespace std;

// Three approaches possible
// 1. Naive Approach - O(N)
// 2. Optimized Approach - O(sqrt N)
// 3. Sieve Approach


// 2-> A factor will be lie in less than sqrt N and other one greater than sqrt N
// so keep checking for < sqrt N
// and if there is no factor (< sqrt N) => number is itself prime

void prime_factoristaion(int N) {
	vector<pair<int, int>> factors;
	int i, count;
	for (i = 2; i * i <= N; i++) {
		// factor will be less than sqrt N
		if (N % i == 0) {
			count = 0;
			// Keep on dividing by i until it is divisble
			while (N % i == 0) {
				N = N / i;
				count++;
			}
			factors.push_back(make_pair(i, count));
		}
	}
	if (N != 1) {
		// whatever left is itself a prime number
		factors.push_back(make_pair(N, 1));
	}

	for (auto it : factors) {
		cout << it.first << "^" << it.second << endl;
	}
}


int main() {
	int N;
	cin >> N;

	cout << "Prime factors are:" << endl;
	prime_factoristaion(N);

}