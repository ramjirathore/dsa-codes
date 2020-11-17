#include<bits/stdc++.h>
using namespace std;

int main()
{
	int x[100];
	cout << sizeof(x) << endl;


	int n;
	cin >> n;
	int *a = new int[n];
	cout << sizeof(a) << endl;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cout << a[i] << " ";
	}

	delete []a;

	return 0;
}