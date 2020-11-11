#include<iostream>
#include<cstring>
using namespace std;

void replacePi(char s[], int i) {
	//base case
	if (s[i] == '\0' or s[i + 1] == '\0') {
		return;
	}

	// rec case
	// check for occurence of pi
	if (s[i] == 'p' and s[i + 1] == 'i') {
		// shift characters ahead of it + replace pi by 3.14
		int j = i + 2;

		// move j to end of array
		while (j != '0') {
			j++;
		}

		// shift the characters (right to left)
		while (j >= i + 2) {
			s[j + 2] = s[j];
			j--;
		}

		// replacement
		s[i] = '3';
		s[i + 1] = '.';
		s[i + 2] = '1';
		s[i + 3] = '4';

		// recursive call for remaining part
		replacePi(s, i + 4);

	} else {
		// go to next position
		replacePi(s, i + 1);
	}
}

int main() {
	char s[100];
	cin >> s;

	replacePi(s, 0);
	cout << s;

	return 0;
}