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

// Total no. of divisors (p+1)(q+1)(r+1)...
// p, q, r.. are powers of prime no.s
// O(logN)
int no_of_divisors(int n, vector<int> &primes) {
	int ans = 1;
	int i = 0;
	int p = primes[0];

	while (p * p <= n) {
		int count = 0;
		if (n % p == 0) {
			while (n % p == 0) {
				count ++;
				n = n / p;
			}
			ans = ans * (count + 1);
		}
		i++;
		p = primes[i];
	}

	if (n != 1) {
		ans = ans * 2;
	}

	return ans;
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
		int totalDivisors = no_of_divisors(n, sieve);
		cout << totalDivisors << endl;
	}

}