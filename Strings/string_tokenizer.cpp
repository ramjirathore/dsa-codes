#include<iostream>
#include<cstring>
using namespace std;

int main() {
	char s[100] = "This is a good and bad thing";
	char *ptr = strtok(s, " ");
	cout << ptr << endl;

	while (ptr != NULL) {
		// Note that after first time we pass NULL
		// Since the ptr maintains a static variable to string
		ptr = strtok(NULL, " ");
		cout << ptr << endl;
	}
}
