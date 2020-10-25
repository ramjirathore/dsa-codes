#include<iostream>
#include<vector>
using namespace std;

#define ll long long


// Problem - Count no. of primes between a given range 'a' and 'b'. Answer Q(<=1000) such queries.
// Soln - Precompute sum .. => O(Q+N)


// Note - if we compute for each query then we will get TLE (since 10^3*10^6 won't run and thus TLE)
// so we precompute sum and then answer in O(1)

void primeSieve(vector<int> &p, int R) {
	//make odd ones prime
	for (ll i = 3; i <= R; i += 2) {
		p[i] = 1;
	}

	for (ll i = 3; i <= R; i += 2) {
		// if current is marked => it is Prime
		if (p[i] == 1) {
			// mark multiples of i to non prime
			for (ll j = i * i; j <= R; j += i) {
				p[j] = 0;
			}
		}
	}

	// special case
	p[2] = 1;
	p[0] = p[1] = 0;

}

int main() {
	int R = 1000005;
	vector<int> prime(R, 0);
	vector<int> cSum(R, 0);

	primeSieve(prime, R);

	//precomputing sum
	for (int i = 2; i <= R; i++) {
		cSum[i] = cSum[i - 1] + prime[i];
	}

	int Q;
	cin >> Q;

	while (Q--) {
		int a, b;
		cin >> a >> b;
		cout << cSum[b] - cSum[a - 1] << endl;
	}

	return 0;
}