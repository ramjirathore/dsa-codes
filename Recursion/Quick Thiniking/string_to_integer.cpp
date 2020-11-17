#include<iostream>
#include<cstring>
using namespace std;

int stringToInt(char *a, int n) {
	// base case
	if (n == 0) {
		return 0;
	}

	// rec case
	int last_digit = a[n - 1] - '0';
	int small_ans = stringToInt(a, n - 1);

	return small_ans * 10 + last_digit;
}

int main() {
	char s[] = "1234";
	int len = strlen(s);

	int ans = stringToInt(s, len);
	cout << ans;
}