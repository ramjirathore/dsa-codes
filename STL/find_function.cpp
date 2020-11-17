#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int a[] = { 1, 10, 11, 45, 29};
	int n = sizeof(a) / sizeof(int);

	int key;
	cin >> key;
	auto it = find(a, a + n, key);
	int index = it - a;

	if (index == n) { // returns n if not in array
		cout << key << " not present";
	} else {
		cout << "Present at index " << index;
	}

	return 0;
}