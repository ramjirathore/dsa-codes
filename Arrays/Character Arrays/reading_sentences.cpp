#include<iostream>
using namespace std;

void readline(char a[], int maxLen, char delim = '\n') {
	int i = 0;
	char ch = cin.get();
	while (ch != delim) {
		a[i] = ch;
		i++;
		if (i == maxLen - 1) {
			break;
		}
		ch = cin.get();
	}
	a[i] = delim;
}

int main() {
	char a[100];
	// user defined
	// readline(a, 100);

	// in built
	cin.getline(a, 100);
	cout << a;
}