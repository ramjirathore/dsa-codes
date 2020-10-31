#include<iostream>
using namespace std;

// Easiest way to approach to Recursion Problems
// "MAGICAL" Recursion Rule = Principle of Mathematical Induction (PMI)

//1. Figure out the Base Case
//** 2. Assume Sub Problems can be solved by recursion(automatically)
//3. Using the sub-problems write the answer for the current problem.

int fact(int n) {

	// Base case
	if (n == 0) {
		return 1;
	}

	return n * fact(n - 1);

}


int main() {
	int N;
	cin >> N;

	cout << fact(N);

	return 0;
}