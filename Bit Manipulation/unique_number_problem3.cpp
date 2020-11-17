#include<iostream>
#include<vector>
using namespace std;

// Problem- Given array of n integers. All numbers repeat thrice except one number
// You have to find tha number

// Soln - O(1) ie in constant space

int main() {
	// see we can't simply do xor of all numbers
	// it won't give any meaningful result

	// Approach -

	vector<int> v(64); // constant size vector
	int totalNums;
	cin >> totalNums;
	int input;

	// store each bit of each number (also add prev num bit to it)
	for (int i = 0; i < totalNums; i++) {
		cin >> input;

		int j = 0;
		//pushing each bit
		while (input > 0) {
			int last_bit = input & 1;
			v[j] += last_bit;
			j++;
			input >>= 1;
		}
	}

	// Note - Remember all bits are stored in reverse
	// Do mod by 3 -> removes repeating 3N numbers bit
	// left with only unique numbers bit
	int p = 1, unq_num = 0;
	for (int i = 0; i < v.size(); i++) {
		v[i] %= 3;
		unq_num +=  v[i] * p;
		p *= 2;

	}
	cout << unq_num;
}