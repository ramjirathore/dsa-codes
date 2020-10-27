#include<iostream>
#include<vector>
using namespace std;


// Soln - O(Q + logN) { only if we ignore the precomputed time of NloglogN}


// O(NloglogN)
vector<int> prime_sieve(vector<int> &p, int n) {
	for (int i = 3; i <= n; i += 2) {
		p[i] = 1;
	}

	for (int i = 3; i <= n; i += 2) {
		if (p[i] == 1) {
			for (int j = i * i; j <= n; j += i) {
				p[j] = 0;
			}
		}
	}

	//special case
	p[2] = 1;
	p[0] = p[1] = 0;

	vector<int> primes;
	for (int i = 0; i <= n; i++) {
		if (p[i] == 1) {
			primes.push_back(i);
		}
	}

	return primes;
}

// O(logN)
vector<int> prime_factorisation(int n, vector<int> &primes) {

	vector<int> factors;
	factors.clear();

	int i = 0;
	int p = primes[0];

	while (p * p <= n) {
		if (n % p == 0) {
			factors.push_back(p);
			while (n % p == 0) {
				n = n / p;
			}
		}
		i++;
		p = primes[i];
	}

	if (n != 1) {
		factors.push_back(n);
	}

	return factors;
}



int main() {
	int N = 10000;
	vector<int> primes(N, 0);
	vector<int> sieve = prime_sieve(primes, N);


	int Q;
	cin >> Q;
	while (Q--) {
		int n;
		cin >> n;
		vector<int> factors = prime_factorisation(n, sieve);
		for (auto it : factors) {
			cout << it << " ";
		}
		cout << endl;
	}

}