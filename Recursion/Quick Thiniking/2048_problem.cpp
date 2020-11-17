#include<iostream>
using namespace std;

string words[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
void printSpellings(int n) {
	//base case
	if (n == 0) {
		return;
	}

	// rec case
	printSpellings(n / 10); // (204)
	int digit = n % 10;
	cout << words[digit] << " ";

}

int main() {
	int n;
	cin >> n;

	// for ex - passing 2048
	printSpellings(n);
}