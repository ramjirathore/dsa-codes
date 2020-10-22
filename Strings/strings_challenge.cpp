#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

string extractStringAtKey(string s, int key) {
	char *ptr = strtok((char*)s.c_str(), " ");
	while (key > 1) {
		ptr = strtok(NULL, " ");
		key--;
	}

	return (string)ptr;
}

int convertToInt(string s) {
	int ans  = 0;
	int p = 1;
	for (int i = s.length() - 1; i > 0; i--) {
		ans += (s[i] - '0') * p;
		p *= 10;
	}
	return ans;
}

bool numericCompare(pair<string, string> s1, pair<string, string> s2) {
	return convertToInt(s1.second) < convertToInt(s2.second);
}
bool lexicoCompare(pair<string, string> s1, pair<string, string> s2) {
	return s1.second < s2.second;;
}

int main() {
	int n;
	cin >> n;
	cin.get();

	string s[100];

	for (int i = 0; i < n; i++) {
		getline(cin, s[i]);
	}

	int key;
	string reversal, ordering;
	cin >> key >> reversal >> ordering;

	pair<string, string> strpair[n];

	// 1.String tokenization
	// extracting that key token from string
	for (int i = 0; i < n; i++) {
		strpair[i].first = s[i];
		strpair[i].second = extractStringAtKey(s[i], key);
	}

	//2. Sorting
	// sorting according to numeric//lexicographically
	if (ordering == "numeric") {
		sort(strpair, strpair + n, numericCompare);
	} else if (ordering == "lexico") {
		sort(strpair, strpair + n, lexicoCompare);
	}

	//3.reversal check
	// if reverse is true then reverse the array
	if (reversal == "true") {
		for (int i = 0; i < n / 2; i++) {
			swap(strpair[i], strpair[n - 1 - i]);
		}
	}

	//4. Print original strings
	for (int i = 0; i < n; i++) {
		cout << strpair[i].first << endl;
	}

}