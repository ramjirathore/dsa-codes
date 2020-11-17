#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int a = 10, b = 20;

	swap(a, b);
	cout << a << " " << b << endl;

	cout << "max of two: " << max(a, b) << endl;
	cout << "min of two: " << min(a, b) << endl;

	vector<int> v = {1, 2, 3, 4, 4, 5, 6};

	reverse(v.begin(), v.begin() + 3);
	for (auto it : v) {
		cout << it << " ";
	}


}