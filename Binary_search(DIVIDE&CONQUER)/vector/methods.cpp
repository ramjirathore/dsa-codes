#include<iostream>
#include<vector>
using namespace std;

int main() {
	vector<int> d{1, 2, 3, 10, 14};

	// push_back | O(1) for most of time
	d.push_back(16);

	// pop_back | O(1) removes the last element
	d.pop_back();

	// inserts some element in the middle | O(n)
	d.insert(d.begin() + 3, 4, 100);

	// erase some element in the middle
	d.erase(d.begin() + 2);

	// or erase a range of values
	d.erase(d.begin() + 2, d.begin() + 5);

	//size
	cout << d.size() << endl;
	cout << d.capacity() << endl;

	// we avoid the shrink
	d.resize(18); // only if the size is increasing more memory is allocated
	cout << d.size() << endl;
	cout << d.capacity() << endl;

	// removes all element from the array (doesnt delete the memory allocated by array)
	d.clear();

	// checking empty
	if (d.empty()) {
		cout << "This is an empty vector";
	}

	for (int x : d) {
		cout << x << " ";
	}

	cout << endl;
	d.push_back(10);
	d.push_back(11);
	d.push_back(12);

	// first and last element
	cout << d.front() << endl;
	cout << d.back() << endl;


	// To avoid doubling we use reverse
	// because doubling is an expensive operation

	vector<int> v;

	// Note: comment this and try
	v.reserve(100);

	for (int i = 0; i < 5; i++) {
		v.push_back(20 * i);
		cout << "changing capacity " << v.capacity() << endl;
	}

}