#include<iostream>
#include<vector>

using namespace std;
int main() {
	vector<int> a;
	vector<int> b(5, 10); // five int with value 10.
	vector<int> c(b); // OR vector <int> c(b.begin(), b.end())
	vector<int> d{1, 2, 4, 8, 16};

	// different methods to print

	//traversing normally
	for (int i = 0; i < c.size(); i++) {
		cout << c[i] << " ";
	}
	cout << endl;

	// using iterator
	for (auto it = d.begin(); it != d.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	// for each loop
	for (auto x : d) { // or use int x: d
		cout << x << " ";
	}
	cout << endl;

	// Discuss more functions
	vector<int> v;

	int n;
	cin >>  n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	for (int y : v) {
		cout << y << " ";
	}
	cout << endl;


	// now lets compare and check the differences between v and d
	cout << v.size() << endl;		// current size of array
	cout << v.capacity() << endl;	// size of underlying arrray
	cout << v.max_size() << endl;	// max no. of elements vector can hold in the worst case acc to available memory in the system

	cout << d.size() << endl;
	cout << d.capacity() << endl;
	cout << d.max_size() << endl;


}