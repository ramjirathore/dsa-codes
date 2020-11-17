#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool compare(string a, string b) {
	// Here > is overoaded for strings
	return a > b;
}

int main() {
	int n;
	cin >> n;
	cin.get(); // See this

	string s[100];
	for (int i = 0; i < n; i++) {
		// Also remember this syntax for strings
		// we don't do cin.getline() instead we pass cin inside getline
		getline(cin, s[i]);
	}

	sort(s, s + n, compare);

	for (auto c : s) {
		cout << c << endl;
	}
}