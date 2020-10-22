#include<iostream>
#include<vector>
using namespace std;

void filterChars(string s, int indx) {
	int i = 0;
	while (indx > 0) {
		int last_bit = (indx & 1);
		if (last_bit) {
			cout << s[i];
		}
		indx >>= 1;
		i++;
	}
}

void genSubsets(string s) {
	int n = s.length();
	for (int i = 0; i < (1 << n); i++) {
		filterChars(s, i);
		cout << endl;
	}
}

int main() {
	string s;
	cin >> s;
	genSubsets(s);
}