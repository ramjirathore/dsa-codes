#include<iostream>
#include<cstring>
using namespace std;

void subsets(char s[], bool present) {
	// base case
	if (s[0] == '\0') {
		return;
	}

	if (present) {
		cout << s[0];
		subsets(s + 1, true);
	} else {
		subsets(s + 1, false);
	}

	cout << endl;
}

int main() {
	char s[10];
	cin >> s;
	int len = strlen(s);

	subsets(s, true);
}