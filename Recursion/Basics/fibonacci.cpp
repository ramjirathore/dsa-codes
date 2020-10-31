#include<iostream>
using namespace std;

// 0 1 1 2 3 5 8 13

int fibo(int n) {

	//Base case
	if (n == 0 || n == 1)
	{
		return n;
	}

	// recursive case
	return fibo(n - 1) + fibo(n - 2);
}

int main() {
	int term;
	cin >> term;

	cout << "nth term from starting is " << fibo(term - 1);

	return 0;
}