#include<iostream>
using namespace std;

// #FRIENDS PAIRING PROBLEM
// Given N friends who want to go a party on bikes. Each guy can go as single or as a couple.
// Find the Number of ways in which N friends can go the party.

// Soln - (Use Selection)
// Think if someone goes then as single then ways = 1.f(n-1) ...n-1 for remaining peoples
// Also if in couple then one person has to chose from n-1 people => (n-1 C 1).f(n-2)

int waysToGo(int n) {
	// base case
	if (n == 0 or n == 1) {
		// 0 is also a way
		return 1;
	}
	if (n == 2) {
		return 2;
	}

	//rec case
	return waysToGo(n - 1) + (n - 1) * waysToGo(n - 2);
}

int main() {
	int friends;
	cin >> friends;

	int ways = waysToGo(friends);
	cout << ways;
}