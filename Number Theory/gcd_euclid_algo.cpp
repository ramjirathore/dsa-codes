#include<iostream>
using namespace std;

int calc_gcd(int a, int b) {
	return b == 0 ? a : calc_gcd(b, a % b);
}

int main() {
	int a, b;
	cin >> a >> b;

	int gcd = calc_gcd(a, b);
	int lcm = (a * b) / gcd;

	cout << "gcd: " << gcd << endl;
	cout << "lcm: " << lcm;
}