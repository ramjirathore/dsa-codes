#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> num;
	int n, res = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		num.push_back(t);
		res ^= t;
	}

	// calculating position at which first set bit is there
	int temp = res, pos = 0;
	while ((temp & 1) != 1) {
		pos++;
		temp >>= 1;
	}


	int x = 0, y = 0;
	// calculating the unique two numbers
	for (auto val : num) {
		// ex: pos=2-> 100 & 101
		if ((1 << pos)&val) {
			x ^= val;
		}
	}
	// do the xor with result
	// will get the other one
	y = res ^ x;

	cout << min(x, y) << " " << max(x, y);

	return 0;
}