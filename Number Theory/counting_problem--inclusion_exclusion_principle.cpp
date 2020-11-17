#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

#define ll long long

// Problem - Find number of numbers between 1 and n which are divisible by any of
// the prime numbers less than 20.

// -- Inclusion exclusion principle --
// Inspiration - (here x -> intersection)
// (we know) |A U B| = |A| + |B| - |A x B |
// also |A U B U C| = |A| + |B| + |C| - |A x B| - |B x C| - |C x A| + |A x B x C|
// crux => so basically on odd ones it is + and in even it is -

// Ex problem -  How many numbers < 1000 are there which are multiples of 2, 3 , 5?
// occurence  of 2 = floor(999/2)
// occurence  of 3 = floor(999/3)
// occurence  of 5 = floor(999/5)
// occurence  of 2 and 3 = floor(999/2*3)
// occurence  of 3 and 5 = floor(999/3*5)..
//..similarly you can see the denomnator is changing

// SOLN -
// => we can create subsets using bitmasking for denominator
// and add/subtract result acc to odd/even respectively

int main() {
	int T;
	cin >> T;


	while (T--) {
		int N;
		cin >> N;
		ll primes[] = {2, 3, 5, 7, 11, 13, 17, 19};


		ll subsets = (1 << 8) - 1;
		ll ans = 0;

		// 1 to 2^N-1
		for (ll i = 1; i <= subsets; i++) {

			ll den = 1ll;
			ll setBits = __builtin_popcount(i);

			for (ll j = 0; j <= 7; j++) {
				if ((i & (1 << j)) > 0) {
					// calculating denominator for i subset
					den = den * primes[j];
				}
			}

			// checking if count of numbers in den is odd
			if (setBits & 1 > 0) {
				ans += floor(N / den);
			} else {
				ans -= floor(N / den);
			}
		}

		cout << ans << endl;

	}

}