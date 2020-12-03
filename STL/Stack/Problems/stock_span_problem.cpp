#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// Problem - Given prices of the days. Find stock span of each day
// Note - stock span = index of current day - index of previous highest day (ie greater than current day stock)



// O(N) time soln
void stockSpan(vector<int> price, int n, vector<int> &span) {
	stack<int> s; // indices of the days
	s.push(0);
	span[0] = 1;

	// loop for the rest of the days
	for (int i = 1; i < n; i++) {
		int currentPrice = price[i];

		// topmost elemenet that is greater than current price
		while (!s.empty() and price[s.top()] <= currentPrice) {
			s.pop();
		}

		if (!s.empty()) {
			int prevHighest = s.top();
			span[i] = i - prevHighest;
		} else {
			span[i] = i + 1;
		}

		s.push(i);
	}
}

int main() {
	vector<int> price = {100, 80, 60, 70, 60, 75, 85};
	int n = price.size();
	vector<int> span (n, 0);

	stockSpan(price, n, span);

	for (auto val : span) {
		cout << val << " ";
	}

}